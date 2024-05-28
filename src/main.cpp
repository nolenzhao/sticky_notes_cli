#include <iostream>
#include <dirent.h>
#include <cerrno>
#include <sys/types.h>
#include <vector>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>
#include <sys/xattr.h>
#include <string>
#include <sqlite3.h>


const std::string stickies_sqlite_db_file = "/Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/build/sticky_notes.db";
const std::string stickies_sqlite_db = "sticky_notes";
const char* STICKY_ATTRIBUTE = "user.has_sticky_note";

int list_callback(void*  data, int argc, char** argv, char**azColName){
    std::vector<std::string>* buf = static_cast<std::vector<std::string>*>(data);

    // process each colum in the current row 
    for(int i = 0; i < argc; i++){
        if(argv[i]){
            buf->push_back(argv[i]);
        }
    }
    return 0;
}
int ino_callback(void*  data, int argc, char** argv, char**azColName){
    std::vector<ino_t>* buf = static_cast<std::vector<ino_t>*>(data);

    // process each colum in the current row 
    for(int i = 0; i < argc; i++){
        if(argv[i]){
            buf->push_back(static_cast<ino_t>(std::stoul(argv[i])));
        }
    }
    return 0;
}


std::string getcwd(){
    char cwd[PATH_MAX];
    if(getcwd(cwd, sizeof(cwd)) != NULL){
        return std::string(cwd);
    }
    else{
        return std::string("");
    }
}

bool query_valid(int rc, sqlite3* db){
    if(rc != SQLITE_OK){
        std::cerr << "Failed to prepare the statement " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    return true;
}

void display_help(){

    std::cout << "Usage: stickies <command>  [<args>]" << std::endl;
    std::cout << "Commands" << std::endl;
    std::cout << "add <file-path>" << std::endl;
    std::cout << "get <file-path>" << std::endl;
    std::cout << "--help" << std::endl;
}

void set_sticky_flag( const std::string &filePath, bool has_sticky_note){

    const char *attr_name = "user.has_sticky_note";
    const char *attr_value = has_sticky_note ? "1" :  "0"; 
    if (setxattr(filePath.c_str(), attr_name, attr_value, strlen(attr_value), 0, 0) == -1) {
        perror("setxattr");
    }
    else{
        std::cout << "successfully set sticky note attribute on " << filePath << std::endl;
    }
}

ino_t stickiesGetInode(std::string &filePath){
    struct stat fileStat;
    if(stat(filePath.c_str(), &fileStat) == -1){
        throw(std::system_error(errno, std::generic_category(), "Failed to stat the file" + filePath));
    }
    return fileStat.st_ino;
}
bool isSticky(std::string &filePath, sqlite3* db){
    ino_t ino_number = stickiesGetInode(filePath);

    const std::string query = "SELECT DISTINCT inode FROM " + stickies_sqlite_db;

    char* errmsg = nullptr;

    std::vector<int> buf;

    int rc = sqlite3_exec(db, query.c_str(), ino_callback, &buf, &errmsg);

    if(rc != SQLITE_OK){
        std::cerr << "Error in retrieving results" << std::endl;
        sqlite3_free(errmsg);
        throw(std::runtime_error("Couldn't query database"));
    }

    bool isSticky = std::find(buf.begin(), buf.end(), ino_number) != buf.end();

    return isSticky; 
    
}


bool database_exists(const std::string &db_name){
    std::ifstream db_file(db_name);
    return db_file.good();
}

void init_sticky_db(sqlite3* &db){
    int rc = sqlite3_open(stickies_sqlite_db_file.c_str(), &db);

    if(rc){
        std::cerr << "can't open the database: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    // SQL statement to create the table if it does not exist

    std::string create_table_sql = "CREATE TABLE IF NOT EXISTS "  + stickies_sqlite_db + " ("
                                   "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                   "inode INTEGER, "
                                   "file_path TEXT, "
                                   "note TEXT, "
                                   "timestamp DATETIME DEFAULT CURRENT_TIMESTAMP, "
                                   "author TEXT, "
                                   "tags TEXT, "
                                   "priority INTEGER);";

    char* err_msg = nullptr;

    rc = sqlite3_exec(db, create_table_sql.c_str(), 0, 0, &err_msg);
    if(rc != SQLITE_OK){
        std::cerr << "SQL error: " << err_msg << std::endl;
        sqlite3_free(err_msg);
    }
}

void add_sticky(sqlite3* db, const std::string &filePath, std::string note){
    struct stat file_stat;

    if(stat(filePath.c_str(), &file_stat) == -1){
        throw std::runtime_error("File not found, could not stat\n");
    }

     
    const char* sql_query = "INSERT INTO sticky_notes (inode, file_path, note, author, tags, priority) VALUES (?, ?, ?, ?, ?, ?);";
    sqlite3_stmt* stmt;

    int rc = sqlite3_prepare_v2(db, sql_query, -1, &stmt, 0);

    if(query_valid(rc, db)){

        sqlite3_bind_int64(stmt, 1, file_stat.st_ino);
        sqlite3_bind_text(stmt, 2, filePath.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, note.c_str(), -1, SQLITE_STATIC);

        if(sqlite3_step(stmt) != SQLITE_DONE){
            throw std::runtime_error("SQL error: " + std::string(sqlite3_errmsg(db)));
        }
        else{
            std::cout << "Successfully added a note" << std::endl;
        }
    }
    else{
        throw std::runtime_error("Error adding a sticky to this file\n");
    }
}


std::string get_sticky(const std::string &filePath, sqlite3* db){

    std::string sqlite_query = "SELECT note FROM " + stickies_sqlite_db + " WHERE file_path = ?";
    sqlite3_stmt* stmt;
    
    std::string content_buf;

    int rc = sqlite3_prepare_v2(db, sqlite_query.c_str(), -1, &stmt, 0);

    if(query_valid(rc, db)){ 
        sqlite3_bind_text(stmt, 1, filePath.c_str(), -1, SQLITE_STATIC);    

        rc = sqlite3_step(stmt);

        if(rc == SQLITE_ROW){
            content_buf = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        }
        else{
            throw std::runtime_error("No sticky found for the file path: " + filePath);
        }
        sqlite3_finalize(stmt);

        return content_buf; 
    }
    else{
        sqlite3_finalize(stmt);
        throw std::runtime_error("Couldn't prepare the query: " + std::string(sqlite3_errmsg(db)));
    }
}

void edit_sticky(std::string &filePath, sqlite3* db){

    if(isSticky(filePath, db)){
        
    }

     

}

bool delete_sticky(const std::string &filePath, sqlite3* db){
    const std::string sql_query = "DELETE FROM " + stickies_sqlite_db + " WHERE file_path = ?";
    sqlite3_stmt *stmt;

    int rc = sqlite3_prepare_v2(db, sql_query.c_str(), -1, &stmt, 0);

    if(!query_valid(rc, db)){
        std::cerr << "Failed to delete the sticky" << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }

    sqlite3_bind_text(stmt, 1, filePath.c_str(), -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);

    if(rc != SQLITE_DONE){
        std::cerr << "Failed to delete the row: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }  

    int changes = sqlite3_changes(db);
    sqlite3_finalize(stmt);

    if(!changes){
        std::cerr << "No sticky found for the file path: " << filePath << std::endl;
        return false;
    }

    return true;
}

void list_stickies(sqlite3* db){

    std::string query = "SELECT DISTINCT file_path FROM " + stickies_sqlite_db; 

    char *errmsg = nullptr; 
    std::vector<std::string> buf; 

    int rc = sqlite3_exec(db, query.c_str(), list_callback, &buf, &errmsg); 
    if(rc != SQLITE_OK){
        std::cerr << "Error in retrieving results" << std::endl;
        sqlite3_free(errmsg);
    }

    for(int i = 0; i < buf.size() ; i++){
        std::cout  << buf[i] << std::endl;
    }
}

void ls_highlighted(sqlite3* db){
    DIR* dir;
    struct dirent* entry;
     
    char cwd[PATH_MAX];

    if(getcwd(cwd, PATH_MAX) == NULL){
        std::cerr << "Couldn't get the current working directory" << std::endl;
        return;
    }

    if((dir = opendir(cwd))== NULL){
        std::cerr << "Couldn't open the current working directory" << std::endl;
        return;
    }

    while((entry =readdir(dir)) != NULL){
        std::string filePath = std::string(cwd) + "/" + entry->d_name;
        
        if(entry->d_type == DT_REG){
            if(isSticky(filePath, db)){
                std::cout << "\033[33m" << entry->d_name << "\033[0m" << std::endl;
            }
            else{
                std::cout << entry->d_name << std::endl;
            }
        }
        else if(entry->d_type == DT_DIR){
              if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                std::cout << entry->d_name << "/" << std::endl;
            }
        }
    }
    closedir(dir);
}
int main(int argc, char *argv[]) {


    if(argc < 2){ 
        display_help();
        return 1;
    }
    std::string command = argv[1];

    sqlite3 * db_connection;
    if(!database_exists(stickies_sqlite_db_file)){
        std::cout << "Database does not exist. Initializing SQLite database." << std::endl;
        init_sticky_db(db_connection);
    }
    else{
        // Open the existing db
        int rc = sqlite3_open(stickies_sqlite_db_file.c_str(), &db_connection);

        if(rc){
            std::cerr << "Can't open this database: " << sqlite3_errmsg(db_connection) << std::endl;
            return 1;
        } 
    }

    
    if(command == "--help" || command == "-h"){
        display_help();
    }

    else if(command == "add"){
        if(argc < 4){
            std::cerr << "'add' requires at least two additional argument. See --help for more details" << std::endl;
            return 1;
        }

        const std::string filePath = argv[2];
        const std::string note = argv[3];

        try{
        add_sticky(db_connection, filePath , note);
        }
        catch(std::runtime_error &e){
            std::cerr << "Error: " << e.what() << std::endl;
            return 1;
        }
    }
    else if(command == "get"){
        if(argc < 3){
            std::cerr << "'get' requires at least one additional argument. See --help for more details" << std::endl;
            return 1;
        }
        
        const std::string filePath = argv[2];
        std::string contents;
        try{
            contents = get_sticky(filePath, db_connection);
        }
        catch (const std::runtime_error & e){
            std::cerr << "Error: " << e.what() << std::endl;
            return 1;
        }

        std::cout << contents << std::endl;

    }
    else if(command == "delete"){
        if(argc < 3){
            std::cerr << "'delete' requires at least one additional argument" << std::endl;
            return 1;
        }
        
        const std::string filePath = argv[2];
        if(!delete_sticky(filePath, db_connection)){
            std::cerr << "Could not delete sticky" << std::endl;
        } 
        else{
            std::cout << "Sticky deleted successfully" << std::endl;
        }
    }
    else if(command == "ls"){
        ls_highlighted(db_connection);
    }
    
    else if(command == "all"){
        list_stickies(db_connection);
    }

}

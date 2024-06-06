#include <iostream>
#include <sys/event.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fts.h>
#include <stdexcept>
#include <dirent.h>
#include <sstream> 
#include <fstream> 
#include <cerrno>
#include <vector>
#include <limits.h>
#include <sys/xattr.h>
#include <string>
#include <sqlite3.h>
#include "headers/utils.h"
#include "headers/commands.h"
#include "headers/callbacks.h"

const std::string stickies_sqlite_db_file = "/Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/build/sticky_notes.db";
const std::string stickies_sqlite_db = "sticky_notes";
const char* STICKY_ATTRIBUTE = "user.has_sticky_note";




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


void edit_sticky(std::string &filePath, sqlite3* db){

    if(!isSticky(filePath, db)){
        std::cerr << "File is not a sticky, please create the sticky first" << std::endl;         
        throw std::runtime_error("Couldn't edit the sticky");
    }

    ino_t fileInode = stickiesGetInode(filePath);

    std::string query = "SELECT note FROM " + stickies_sqlite_db + " WHERE inode = ?"; 

    sqlite3_stmt *stmt;

    int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, 0);

    if(!query_valid(rc, db)){
        std::cerr << "Query not valid" << std::endl;
        sqlite3_finalize(stmt);
        throw std::runtime_error("Couldn't edit the sticky");
    }
    

    rc = sqlite3_bind_int(stmt, 1, static_cast<int>(fileInode));

    if(rc != SQLITE_OK){
        std::cerr << "Failed to bind inode to query" << std::endl;
        sqlite3_finalize(stmt);
        throw std::runtime_error("Couldn't edit sticky");
    }

    rc = sqlite3_step(stmt);

    if(rc != SQLITE_ROW){
        std::cerr << "Failed to retrieve the sticky" << std::endl;
        sqlite3_finalize(stmt);
        throw std::runtime_error("Couldn't edit sticky");
    }


    const char * note = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)); 
    std::string editingFile = "/tmp/stkn_editor.txt";
    

    std::ofstream tempFile(editingFile);

    if(!tempFile){
        std::cerr << "Failed to create an editing file" << std::endl;
        sqlite3_finalize(stmt);
        throw std::runtime_error("Couldn't edit the sticky");
    }

    tempFile << note << std::endl;
    tempFile.close();
            
    sqlite3_finalize(stmt);

    std::string fileCommand = "vim " + editingFile; 
    system(fileCommand.c_str());

    std::ifstream updatedFile(editingFile);

    if(!updatedFile){
        std::cerr << "Failed to edit the file" << std::endl;
        throw std::runtime_error("File not edited");
    }

    std::stringstream stringStream;


    stringStream << updatedFile.rdbuf();
    std::string updatedString = stringStream.str();

    std::string updateQuery = "UPDATE " + stickies_sqlite_db + " SET note = ? where inode = ?";

    sqlite3_stmt* stmt2;
  
    rc = sqlite3_prepare_v2(db, updateQuery.c_str(), -1, &stmt2, 0);
        
    if(!query_valid(rc, db)){
        std::cerr << "Couldn't edit the file" << std::endl;
        sqlite3_finalize(stmt2);
        throw std::runtime_error("Couldn't query the data bse");
    }

    rc = sqlite3_bind_text(stmt2, 1, updatedString.c_str(), -1, SQLITE_TRANSIENT);

    if(rc != SQLITE_OK){
        std::cerr << "Failed to bind text to the query" << std::endl;
        sqlite3_finalize(stmt2);
        throw std::runtime_error("Filed not edited");
    }

    rc = sqlite3_bind_int(stmt2, 2, static_cast<int>(fileInode));
        
    if(rc != SQLITE_OK){
        std::cerr << "Failed to bind the inode to the query" << std::endl;
        sqlite3_finalize(stmt2);
        throw std::runtime_error("Filed not edited");
    }

    rc = sqlite3_step(stmt2);

    if(rc != SQLITE_DONE){
        std::cerr << "Failed to execute the query" << std::endl;
        sqlite3_finalize(stmt2);
        throw std::runtime_error("Filed not edited"); 
    }
    
    sqlite3_finalize(stmt2);
}

bool delete_sticky(std::string &filePath, sqlite3* db){

    ino_t inode = stickiesGetInode(filePath);
    
    const std::string sql_query = "DELETE FROM " + stickies_sqlite_db + " WHERE inode = ?";
    sqlite3_stmt *stmt;

    int rc = sqlite3_prepare_v2(db, sql_query.c_str(), -1, &stmt, 0);

    if(!query_valid(rc, db)){
        std::cerr << "Failed to delete the sticky" << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }

    sqlite3_bind_int(stmt, 1, static_cast<int>(inode));

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

// Function to find file path by inode
std::string findFilePathByInode(ino_t target_inode, const char* startPath = "/") {
    char* paths[] = {const_cast<char*>(startPath), nullptr};
    FTS* file_system = fts_open(paths, FTS_NOCHDIR | FTS_PHYSICAL, nullptr);

    if (!file_system) {
        throw std::runtime_error("fts_open failed");
    }

    FTSENT* node;
    while ((node = fts_read(file_system)) != nullptr) {
        if (node->fts_info & FTS_F) {
            if (node->fts_statp->st_ino == target_inode) {
                std::string filePath = node->fts_path;
                fts_close(file_system);
                return filePath;
            }
        }
    }

    fts_close(file_system);
    return "File not found";
}

void list_stickies(sqlite3* db){

    std::string query = "SELECT DISTINCT inode FROM " + stickies_sqlite_db; 

    char *errmsg = nullptr; 
    std::vector<int> buf; 

    int rc = sqlite3_exec(db, query.c_str(), ino_callback, &buf, &errmsg); 
    if(rc != SQLITE_OK){
        std::cerr << "Error in retrieving results" << std::endl;
        sqlite3_free(errmsg);
    }

    for(int i = 0; i < buf.size() ; i++){
        std::string filePath = findFilePathByInode(static_cast<ino_t>(buf[i]));
        std::cout << filePath << std::endl;
    }
}

void ls_highlighted(sqlite3* db){
    DIR* dir;
    struct dirent* entry;

    std::string cwd = easyGetCwd();

    if((dir = opendir(cwd.c_str()))== NULL){
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

        std::string filePath = argv[2];
        std::string note = argv[3];

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
        
        std::string filePath = argv[2];
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
    else if(command == "edit"){
        if(argc < 3){
            std::cerr << "'edit' requires at least one additional argument" << std::endl;
            return 1;
        }

        std::string filePath = argv[2];
        
        edit_sticky(filePath, db_connection);
    }
    else if(command == "delete"){
        if(argc < 3){
            std::cerr << "'delete' requires at least one additional argument" << std::endl;
            return 1;
        }
        
        std::string filePath = argv[2];
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

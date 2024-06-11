#include <iostream>
#include <unistd.h>
#include <vector>
#include <fstream>
#include <sys/stat.h>
#include "utils.h"
#include "callbacks.h"
#include "constants.h"
#include <fts.h>



void init_sticky_db(sqlite3* &db){
    int rc = sqlite3_open(STICKIES_SQLITE_DB_FILE.c_str(), &db);

    if(rc){
        std::cerr << "can't open the database: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    std::string create_table_sql = "CREATE TABLE IF NOT EXISTS "  + STICKIES_SQLITE_DB + " ("
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

bool database_exists(const std::string &db_name){
    std::ifstream db_file(db_name);
    return db_file.good();
}

std::string easyGetCwd(){
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


ino_t stickiesGetInode(const std::string &filePath){
    struct stat fileStat;
    if(stat(filePath.c_str(), &fileStat) == -1){
        throw(std::system_error(errno, std::generic_category(), "Failed to stat the file" + filePath));
    }
    return fileStat.st_ino;
}


bool isSticky(const std::string &filePath, sqlite3* db){
    ino_t ino_number = stickiesGetInode(filePath);

    const std::string query = "SELECT DISTINCT inode FROM " + STICKIES_SQLITE_DB;

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


std::string getAbsolutePath(std::string& relativePath) {
    char absolutePath[PATH_MAX];
    if (realpath(relativePath.c_str(), absolutePath) == NULL) {
        std::cerr << "Error resolving the absolute path" << std::endl;
        return "";
    }
    return std::string(absolutePath);
}


// Function to find file path by inode
std::string findFilePathByInode(ino_t target_inode, const char* startPath) {
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




void updateFilePathChanges(sqlite3* &db, ino_t inode, const std::string &newFilePath){

    int rc = sqlite3_open(STICKIES_SQLITE_DB_FILE.c_str(), &db);
    char* errmsg = nullptr;

    std::string query = "UPDATE " + STICKIES_SQLITE_DB + " SET file_path = '" + newFilePath + "' WHERE inode = " + std::to_string(inode) + ";";

    rc = sqlite3_exec(db, query.c_str(), 0, 0, &errmsg);

    if(rc != SQLITE_OK){
        std::cerr << "Unable to execute the query" << std::endl;
        sqlite3_free(errmsg);
        throw std::runtime_error("Unable to update file path in database");
    }

    sqlite3_close(db);
}
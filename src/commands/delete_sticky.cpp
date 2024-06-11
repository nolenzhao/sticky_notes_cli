
#include <iostream>
#include <sys/stat.h>
#include "commands.h"
#include "constants.h"
#include "utils.h"


void delete_sticky(sqlite3* db, std::string &filePath){

    ino_t inode = stickiesGetInode(filePath);
    
    const std::string sql_query = "DELETE FROM " + STICKIES_SQLITE_DB + " WHERE inode = ?";
    sqlite3_stmt *stmt;

    int rc = sqlite3_prepare_v2(db, sql_query.c_str(), -1, &stmt, 0);

    if(!query_valid(rc, db)){
        std::cerr << "Query not valid" << std::endl;
        sqlite3_finalize(stmt);
        throw std::runtime_error("Failed to delete sticky"); 
    }

    sqlite3_bind_int(stmt, 1, static_cast<int>(inode));

    rc = sqlite3_step(stmt);

    if(rc != SQLITE_DONE){
        std::cerr << "Failed to delete the row: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        throw std::runtime_error("Failed to delete sticky");
    }  

    int changes = sqlite3_changes(db);
    sqlite3_finalize(stmt);

    if(!changes){
        std::cerr << "No sticky found for the file path: " << filePath << std::endl;
        throw std::runtime_error("Failed to delete sticky");
    }  
}
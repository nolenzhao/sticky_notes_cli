#include <sys/stat.h>
#include "commands.h"
#include "utils.h"

const std::string STICKIES_SQLITE_DB = "sticky_notes";

std::string get_sticky(const std::string &filePath, sqlite3* db){

    ino_t inode = stickiesGetInode(filePath);

    std::string sqlite_query = "SELECT note FROM " + STICKIES_SQLITE_DB + " WHERE inode = ?";

    sqlite3_stmt* stmt;
    
    std::string content_buf;

    int rc = sqlite3_prepare_v2(db, sqlite_query.c_str(), -1, &stmt, 0);

    if(query_valid(rc, db)){ 

        sqlite3_bind_int(stmt, 1, static_cast<int>(inode));    

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

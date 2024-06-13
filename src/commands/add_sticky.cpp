#include <sys/stat.h>
#include <iostream>
#include "utils.h"
#include "commands.h"
#include "constants.h"
#include "globals.h"

void add_sticky(sqlite3* db, const std::string &filePath, std::string note){

    
    sqlite3_open(STICKIES_SQLITE_DB_FILE.c_str(), &db);

    struct stat file_stat;

    if(stat(filePath.c_str(), &file_stat) == -1){
        throw std::runtime_error("File not found, could not stat\n");
    }

     
    const std::string query = "INSERT INTO " + STICKIES_SQLITE_DB + " (inode, file_path, note, author, tags, priority) VALUES (?, ?, ?, ?, ?, ?);";

    sqlite3_stmt* stmt;
    std::string absoluteFilePath = getAbsolutePath(filePath);

    int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, 0);

    if(query_valid(rc, db)){

        sqlite3_bind_int64(stmt, 1, file_stat.st_ino);
        sqlite3_bind_text(stmt, 2, absoluteFilePath.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, note.c_str(), -1, SQLITE_STATIC);

        if(sqlite3_step(stmt) != SQLITE_DONE){
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            throw std::runtime_error("SQL error: " + std::string(sqlite3_errmsg(db)));
        }
        else{
            std::cout << "Successfully added a note" << std::endl;
            inodeToFileMap[file_stat.st_ino] = filePath;
            sqlite3_close(db);
        }
    }
    else{
        sqlite3_close(db);
        throw std::runtime_error("Error adding a sticky to this file\n");
    }

}

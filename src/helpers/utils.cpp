#include <iostream>
#include <unistd.h>
#include <sys/stat.h>
#include "utils.h"

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


ino_t stickiesGetInode(std::string &filePath){
    struct stat fileStat;
    if(stat(filePath.c_str(), &fileStat) == -1){
        throw(std::system_error(errno, std::generic_category(), "Failed to stat the file" + filePath));
    }
    return fileStat.st_ino;
}
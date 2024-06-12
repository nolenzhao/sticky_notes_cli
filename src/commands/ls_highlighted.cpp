#include <iostream>
#include <dirent.h>
#include "utils.h"
#include "commands.h"
#include "constants.h"

void ls_highlighted(sqlite3* db){

    sqlite3_open(STICKIES_SQLITE_DB_FILE.c_str(), &db);

    DIR* dir;
    struct dirent* entry;

    std::string cwd = easyGetCwd();

    if((dir = opendir(cwd.c_str()))== NULL){
        std::cerr << "Couldn't open the current working directory" << std::endl;
        sqlite3_close(db);
        throw std::runtime_error("ls_highlighted broken");
    }

    while((entry =readdir(dir)) != NULL){
        const std::string filePath = std::string(cwd) + "/" + entry->d_name;
        
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
                if(isSticky(filePath, db)){
                std::cout << "\033[33m" << entry->d_name << "/" << "\033[0m" << std::endl;
                }
                else{
                std::cout <<  entry->d_name << "/" << std::endl;
                }
            }
        }
    }
    sqlite3_close(db);
    closedir(dir);
}
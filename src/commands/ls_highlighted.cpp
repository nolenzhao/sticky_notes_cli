#include <iostream>
#include <dirent.h>
#include "utils.h"
#include "commands.h"


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
                if(isSticky(filePath, db)){
                std::cout << "\033[33m" << entry->d_name << "/" << "\033[0m" << std::endl;
                }
                else{
                std::cout <<  entry->d_name << "/" << std::endl;
                }
            }
        }
    }
    closedir(dir);
}
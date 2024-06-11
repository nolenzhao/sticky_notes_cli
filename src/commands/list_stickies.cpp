#include <iostream>
#include <sys/stat.h>
#include <vector>
#include "commands.h"
#include "constants.h"
#include "callbacks.h"
#include "utils.h"

void list_stickies(sqlite3* db){

    std::string query = "SELECT DISTINCT inode FROM " + STICKIES_SQLITE_DB; 

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
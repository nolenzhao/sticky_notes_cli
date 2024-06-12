#include <iostream> 
#include <unordered_map>
#include <filesystem>
#include <sys/stat.h>
#include "constants.h"
#include "callbacks.h"
#include "utils.h"
#include "globals.h"


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

// int ino_callback(void*  data, int argc, char** argv, char**azColName){
//     std::vector<ino_t>* buf = static_cast<std::vector<ino_t>*>(data);

//     // process each colum in the current row 
//     for(int i = 0; i < argc; i++){
//         if(argv[i]){
//             buf->push_back(static_cast<ino_t>(std::stoul(argv[i])));
//         }
//     }
//     return 0;
// }

 int ino_callback(void* data, int argc, char** argv, char** azColName) {
    std::vector<int>* buf = static_cast<std::vector<int>*>(data);
    for (int i = 0; i < argc; i++) {
        if (argv[i]) {
            buf->push_back(std::stoi(argv[i]));
        }
    }
    return 0;
}

void fileMonitorCallback(ConstFSEventStreamRef streamRef, void *clientCallBackInfo, size_t numEvents, 
    void* eventPaths, const FSEventStreamEventFlags eventFlags[], const FSEventStreamEventId eventIds[]){


        char **paths = (char**)eventPaths;                        

        for(size_t i = 0; i < numEvents; i++){
            if(eventFlags[i] & kFSEventStreamEventFlagItemRenamed){
                
                struct stat fileStat;

                if(stat(paths[i], &fileStat) == 0){
                    uint64_t inode =  fileStat.st_ino;

                    auto it = inodeToFileMap.find(inode);
                    
                    if(it != inodeToFileMap.end()){
                        sqlite3_stmt *stmt;

                        std::string query = "UPDATE " + STICKIES_SQLITE_DB + " SET file_path = ? WHERE inode = ?";

                        sqlite3_prepare_v2(db_connection, query.c_str(), -1, &stmt, NULL);
                        sqlite3_bind_text(stmt, 1, paths[i], -1, SQLITE_STATIC);
                        sqlite3_bind_int64(stmt, 2, inode);
                        sqlite3_step(stmt);
                        sqlite3_finalize(stmt);

                        inodeToFileMap[inode] = paths[i];
                    }

                }
                
            }
        }
                            

}
#include "constants.h"
#include "callbacks.h"
#include "watcher.h"
#include <CoreServices/CoreServices.h>
#include <unordered_map>

void startFileWatcher(sqlite3* db, std::unordered_map<uint64_t, std::string> &inodeToFileMap, FSEventStreamRef & stream){

    sqlite3_stmt* stmt;

    std::string query = "SELECT inode, file_path FROM " + STICKIES_SQLITE_DB;

    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);

    while(sqlite3_step(stmt) == SQLITE_ROW){
        uint64_t inode = sqlite3_column_int64(stmt, 0);

        const char *file_path = (const char*)sqlite3_column_text(stmt, 1);

        inodeToFileMap[inode] = file_path;
    }
    sqlite3_finalize(stmt);

    CFMutableArrayRef pathsToWatch = CFArrayCreateMutable(NULL, inodeToFileMap.size(), &kCFTypeArrayCallBacks);

    for(const auto &pair : inodeToFileMap){
        CFStringRef path = CFStringCreateWithCString(NULL, pair.second.c_str(), kCFStringEncodingUTF8); 
        CFArrayAppendValue(pathsToWatch, path);
        CFRelease(path);
    }

    FSEventStreamContext context = {0, NULL, NULL, NULL, NULL};

    CFAbsoluteTime latency = 1.0;

    stream = FSEventStreamCreate(NULL,
                                &fileMonitorCallback,
                                &context,
                                pathsToWatch,
                                kFSEventStreamEventIdSinceNow,
                                latency,
                                kFSEventStreamCreateFlagFileEvents | kFSEventStreamCreateFlagUseCFTypes);



}
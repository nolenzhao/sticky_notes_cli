#include "constants.h"
#include "callbacks.h"
#include "watcher.h"
#include "globals.h"
#include <CoreServices/CoreServices.h>
#include <unordered_map>
#include <vector>
#include <iostream>


void startFileWatcher(){

    sqlite3_stmt* stmt;

    std::string query = "SELECT inode, file_path FROM " + STICKIES_SQLITE_DB;

    sqlite3_prepare_v2(db_connection, query.c_str(), -1, &stmt, NULL);

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


    runLoop = CFRunLoopGetCurrent();

    dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
    FSEventStreamSetDispatchQueue(stream, queue);

     // Start the stream
    FSEventStreamStart(stream);

    // Run the loop
    CFRunLoopRun();

    // Clean up
    FSEventStreamStop(stream);
    FSEventStreamInvalidate(stream);
    FSEventStreamRelease(stream);
    CFRelease(pathsToWatch);


}


void fillMap(sqlite3* db){
    std::string query = "SELECT DISTINCT file_path from " + STICKIES_SQLITE_DB;

    char* errmsg = nullptr;

    std::vector<std::string> buf_files;

    sqlite3_open(STICKIES_SQLITE_DB_FILE.c_str(), &db);

    int rc = sqlite3_exec(db, query.c_str(), list_callback, &buf_files, &errmsg);

    if(rc != SQLITE_OK){
        std::cerr << "Error in retrieving results" << std::endl;
        sqlite3_free(errmsg);
        sqlite3_close(db);
        throw(std::runtime_error("Couldn't query database"));
    }

    std::vector<int> buf_int;

    query = "SELECT DISTINCT inode from " + STICKIES_SQLITE_DB;
    rc = sqlite3_exec(db, query.c_str(), ino_callback, &buf_int, &errmsg);
    if(rc != SQLITE_OK){
        std::cerr << "Error in retrieving results" << std::endl;
        sqlite3_free(errmsg);
        sqlite3_close(db);
        throw(std::runtime_error("Couldn't query database"));
    }

    for(int i = 0; i < buf_int.size(); i++){
        inodeToFileMap.insert({buf_int[i], buf_files[i]});
    }

    sqlite3_close(db);
}
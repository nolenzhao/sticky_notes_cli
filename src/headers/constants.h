#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <string> 
#include <CoreServices/CoreServices.h>
#include <unordered_map>
#include <sqlite3.h>
extern const std::string STICKIES_SQLITE_DB;
extern const std::string STICKIES_SQLITE_DB_FILE;
extern const std::string STICKIES_TEMP_FILE;
FSEventStreamRef stream; 
CFRunLoopRef runLoop;
std::atomic<bool> keepRunning(true);
std::unordered_map<uint64_t, std::string> inodeToFileMap;
sqlite3 * db_connection;
#endif
#ifndef GLOBALS_H
#define GLOBALS_H
#include <unordered_map>
#include <string>
#include <CoreServices/CoreServices.h>
#include <sqlite3.h>
extern std::unordered_map<uint64_t, std::string> inodeToFileMap;
extern FSEventStreamRef stream; 
extern CFRunLoopRef runLoop;
extern std::atomic<bool> keepRunning;
extern sqlite3 * db_connection;


#endif
#include "globals.h"

std::unordered_map<uint64_t, std::string> inodeToFileMap;
FSEventStreamRef stream; 
CFRunLoopRef runLoop;
std::atomic<bool> keepRunning;
sqlite3 * db_connection;
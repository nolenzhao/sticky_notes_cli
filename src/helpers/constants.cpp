#include "constants.h"



const std::string STICKIES_SQLITE_DB_FILE = "/Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/build/sticky_notes.db";
const std::string STICKIES_SQLITE_DB = "sticky_notes";
const std::string STICKIES_TEMP_FILE = "/tmp/stkn_editor.txt";
FSEventStreamRef stream; 
CFRunLoopRef runLoop;
std::atomic<bool> keepRunning(true);
std::unordered_map<uint64_t, std::string> inodeToFileMap;
sqlite3 * db_connection;
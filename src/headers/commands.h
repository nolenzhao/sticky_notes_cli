#ifndef COMMANDS_H
#define COMMANDS_H
#include <sqlite3.h>
#include <string>

void display_help();

std::string get_sticky(std::string &filePath, sqlite3* db);

void add_sticky(sqlite3* db, std::string& filePath, std::string note);


#endif
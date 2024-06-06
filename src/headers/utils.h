#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <sqlite3.h>


std::string easyGetCwd();


bool query_valid(int rc, sqlite3* db);

ino_t stickiesGetInode(std::string &filePath);



#endif
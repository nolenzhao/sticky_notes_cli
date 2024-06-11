#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <sqlite3.h>


std::string easyGetCwd();


void init_sticky_db(sqlite3* &db);

bool database_exists(const std::string &db_name);

bool query_valid(int rc, sqlite3* db);

ino_t stickiesGetInode(const std::string &filePath);

bool isSticky(const std::string &filePath, sqlite3* db);

std::string getAbsolutePath(std::string &relativePath);

std::string findFilePathByInode(ino_t target_inode, const char* startPath = "/");

void updateFilePathChanges(sqlite3* db, ino_t inode, const std::string &newFilePath);


#endif
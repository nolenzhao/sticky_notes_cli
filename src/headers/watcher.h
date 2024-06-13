#ifndef WATCHER_H
#define WATCHER_H

#include <sqlite3.h>

void startFileWatcher();

void fillMap(sqlite3* db);

#endif
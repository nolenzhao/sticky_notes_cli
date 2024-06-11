#ifndef CALLBACKS_H
#define CALLBACKS_H

#include<string>
#include<vector>
#include <CoreServices/CoreServices.h>

int list_callback(void* data, int argc, char** argv, char** azColName);

int ino_callback(void* data, int argc, char** argv, char** azColName);


void fileMonitorCallback(ConstFSEventStreamRef streamRef, void *clientCallBackInfo, size_t numEvents, 
    void* eventPaths, const FSEventStreamEventFlags eventFlags[], const FSEventStreamEventId eventIds[]);
#endif 
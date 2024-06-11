#include <csignal>
#include <iostream>
#include <CoreServices/CoreServices.h>
#include "signals.h"

void signalHandler(int signum, FSEventStreamRef &stream, CFRunLoopRef &runLoop, std::atomic<bool> &keepRunning){
    std::cout << "Interrupt signal (" << signum << ") received. Stopping the watcher" << std::endl;

    if(stream){
        FSEventStreamStop(stream);
        FSEventStreamInvalidate(stream);
        FSEventStreamRelease(stream);
        stream = NULL;
    }
    
    if(runLoop){
        CFRunLoopStop(runLoop);
    }
    keepRunning = false;

}
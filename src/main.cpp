#include <iostream>
#include <sys/event.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdexcept>
#include <sstream> 
#include <fstream> 
#include <cerrno>
#include <vector>
#include <limits.h>
#include <string>
#include <sqlite3.h>
#include <CoreServices/CoreServices.h>
#include <unordered_map>
#include <thread>
#include "headers/utils.h"
#include "headers/commands.h"
#include "headers/constants.h"
#include "headers/callbacks.h"
#include "headers/signals.h"
#include "headers/watcher.h"
#include "headers/globals.h"

 

int main(int argc, char *argv[]) {

    signal(SIGINT, signalHandler);
    signal(SIGTERM, signalHandler);




    if(argc < 2){ 
        display_help();
        return 1;
    }
    std::string command = argv[1];

    if(!database_exists(STICKIES_SQLITE_DB_FILE)){
        std::cout << "Database does not exist. Initializing SQLite database." << std::endl;
        init_sticky_db(db_connection);
    }
    else{
        // Open the existing db
        int rc = sqlite3_open(STICKIES_SQLITE_DB_FILE.c_str(), &db_connection);

        if(rc){
            std::cerr << "Can't open this database: " << sqlite3_errmsg(db_connection) << std::endl;
            return 1;
        } 
    }


    std::thread watcherThread(startFileWatcher);
    watcherThread.detach();


    if(command == "--help" || command == "-h"){
        display_help();
    }

    else if(command == "add"){
        if(argc < 4){
            std::cerr << "'add' requires at least two additional argument. See --help for more details" << std::endl;
            return 1;
        }

        std::string filePath = argv[2];
        std::string note = argv[3];

        try{
        add_sticky(db_connection, filePath , note);
        }
        catch(std::runtime_error &e){
            std::cerr << "Error: " << e.what() << std::endl;
            return 1;
        }
    }
    else if(command == "get"){
        if(argc < 3){
            std::cerr << "'get' requires at least one additional argument. See --help for more details" << std::endl;
            return 1;
        }
        
        std::string filePath = argv[2];
        std::string contents;
        try{
            contents = get_sticky(filePath, db_connection);
        }
        catch (const std::runtime_error & e){
            std::cerr << "Error: " << e.what() << std::endl;
            return 1;
        }

        std::cout << contents << std::endl;

    }
    else if(command == "edit"){
        if(argc < 3){
            std::cerr << "'edit' requires at least one additional argument" << std::endl;
            return 1;
        }

        std::string filePath = argv[2];
        
        edit_sticky(db_connection, filePath);
    }
    else if(command == "delete"){
        if(argc < 3){
            std::cerr << "'delete' requires at least one additional argument" << std::endl;
            return 1;
        } 
        std::string filePath = argv[2];
        delete_sticky(db_connection, filePath);
    }
    else if(command == "ls"){
        ls_highlighted(db_connection);
    }    
    else if(command == "all"){
        list_stickies(db_connection);
    }
    else{
        std::cerr << "Not a valid command, see --help for more details";
    }


    while(keepRunning){
          std::this_thread::sleep_for(std::chrono::seconds(1));
    }



    sqlite3_close(db_connection);
    return 0;
}

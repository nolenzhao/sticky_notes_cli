#include "callbacks.h"



int list_callback(void*  data, int argc, char** argv, char**azColName){
    std::vector<std::string>* buf = static_cast<std::vector<std::string>*>(data);

    // process each colum in the current row 
    for(int i = 0; i < argc; i++){
        if(argv[i]){
            buf->push_back(argv[i]);
        }
    }

    return 0;
}

int ino_callback(void*  data, int argc, char** argv, char**azColName){
    std::vector<ino_t>* buf = static_cast<std::vector<ino_t>*>(data);

    // process each colum in the current row 
    for(int i = 0; i < argc; i++){
        if(argv[i]){
            buf->push_back(static_cast<ino_t>(std::stoul(argv[i])));
        }
    }
    return 0;
}
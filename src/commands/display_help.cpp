#include <iostream>

void display_help(){

    std::cout << "Usage: stickies <command>  [<args>]" << std::endl;
    std::cout << "Commands" << std::endl;
    std::cout << "add <file-path>" << std::endl;
    std::cout << "get <file-path>" << std::endl;
    std::cout << "--help" << std::endl;
}
#include <iostream>
#include <fstream>
#include <sstream>
#include "commands.h"
#include "utils.h"
#include "constants.h"
void edit_sticky(sqlite3* db, const std::string &filePath){

    if(!isSticky(filePath, db)){
        std::cerr << "File is not a sticky, please create the sticky first" << std::endl;         
        throw std::runtime_error("Couldn't edit the sticky");
    }

    ino_t fileInode = stickiesGetInode(filePath);

    std::string query = "SELECT note FROM " + STICKIES_SQLITE_DB + " WHERE inode = ?"; 

    sqlite3_stmt *stmt;

    int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, 0);

    if(!query_valid(rc, db)){
        std::cerr << "Query not valid" << std::endl;
        sqlite3_finalize(stmt);
        throw std::runtime_error("Couldn't edit the sticky");
    }
    

    rc = sqlite3_bind_int(stmt, 1, static_cast<int>(fileInode));

    if(rc != SQLITE_OK){
        std::cerr << "Failed to bind inode to query" << std::endl;
        sqlite3_finalize(stmt);
        throw std::runtime_error("Couldn't edit sticky");
    }

    rc = sqlite3_step(stmt);

    if(rc != SQLITE_ROW){
        std::cerr << "Failed to retrieve the sticky" << std::endl;
        sqlite3_finalize(stmt);
        throw std::runtime_error("Couldn't edit sticky");
    }


    const char * note = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)); 
    std::string editingFile = STICKIES_TEMP_FILE;
    

    std::ofstream tempFile(editingFile);

    if(!tempFile){
        std::cerr << "Failed to create an editing file" << std::endl;
        sqlite3_finalize(stmt);
        throw std::runtime_error("Couldn't edit the sticky");
    }

    tempFile << note << std::endl;
    tempFile.close();
            
    sqlite3_finalize(stmt);

    std::string fileCommand = "vim " + editingFile; 
    system(fileCommand.c_str());

    std::ifstream updatedFile(editingFile);

    if(!updatedFile){
        std::cerr << "Failed to edit the file" << std::endl;
        throw std::runtime_error("File not edited");
    }

    std::stringstream stringStream;


    stringStream << updatedFile.rdbuf();
    std::string updatedString = stringStream.str();

    std::string updateQuery = "UPDATE " + STICKIES_SQLITE_DB + " SET note = ? where inode = ?";

    sqlite3_stmt* stmt2;
  
    rc = sqlite3_prepare_v2(db, updateQuery.c_str(), -1, &stmt2, 0);
        
    if(!query_valid(rc, db)){
        std::cerr << "Couldn't edit the file" << std::endl;
        sqlite3_finalize(stmt2);
        throw std::runtime_error("Couldn't query the data bse");
    }

    rc = sqlite3_bind_text(stmt2, 1, updatedString.c_str(), -1, SQLITE_TRANSIENT);

    if(rc != SQLITE_OK){
        std::cerr << "Failed to bind text to the query" << std::endl;
        sqlite3_finalize(stmt2);
        throw std::runtime_error("Filed not edited");
    }

    rc = sqlite3_bind_int(stmt2, 2, static_cast<int>(fileInode));
        
    if(rc != SQLITE_OK){
        std::cerr << "Failed to bind the inode to the query" << std::endl;
        sqlite3_finalize(stmt2);
        throw std::runtime_error("Filed not edited");
    }

    rc = sqlite3_step(stmt2);

    if(rc != SQLITE_DONE){
        std::cerr << "Failed to execute the query" << std::endl;
        sqlite3_finalize(stmt2);
        throw std::runtime_error("Filed not edited"); 
    }
    
    sqlite3_finalize(stmt2);
}

#include <iostream>
#include "TeamBuilder.h"
//#include "DataBase.h"
//#include "sqlite3.h"
#include "Main.cpp"

std::map<std::string, std::pair<std::string, std::string>> TeamBuilder::Names;

TeamBuilder::TeamBuilder() {
}

TeamBuilder::~TeamBuilder() {
}

int Teambuilder(){
   // open_db();  
    std::cout << "Database actief";
    //create_table();  

    main_loop();

    return 0;
}

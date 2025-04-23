#include "Remove.h"
#include <iostream>
#include "TeamBuilder.h"

Remove::Remove(){
}
Remove::~Remove(){
}

void Remove::remove(std::string person) {
    auto& names= TeamBuilder::Names;
    auto it = TeamBuilder::Names.find(person); 

    if (it != names.end()) {
        names.erase(it);  
        std::cout << "Verwijderd: " << person << "\n";
    } 
    else {
        std::cout << "Naam niet gevonden: " << person << "\n";
    }
}



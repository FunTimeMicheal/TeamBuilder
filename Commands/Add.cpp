#include "Add.h"
#include "TeamBuilder.h"
#include <iostream>

Add::Add(){
}
Add::~Add(){
}

void Add::add(std::string person, std::string volwassen, std::string internet) {\
    auto& names =TeamBuilder::Names; 
    names[person] = {volwassen, internet}; 
    std::cout << "Toegevoegd: " << person << " (Volwassen: " << volwassen << ", Internet: " << internet << ")\n";
};

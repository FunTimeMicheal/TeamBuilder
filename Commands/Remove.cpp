#include "Remove.h"
#include <iostream>

class Remove
{
private:
    /* data */
public:
    Remove(/* args */);
    ~Remove();
};

void Remove::remove(std::string person) {
    auto it = Names.find(person); 
if (it != Names.end()) {
        Names.erase(it);  
        std::cout << "Verwijderd: " << person << "\n";
    } else {
        std::cout << "Naam niet gevonden: " << person << "\n";
    }
}

Remove::~Remove()
{
}

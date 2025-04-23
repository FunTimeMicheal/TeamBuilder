#include "NameManager"


class Add{

    void NameManager::add(std::string person, std::string volwassen, std::string internet) {
        Names[person] = {volwassen, internet}; 
        std::cout << "Toegevoegd: " << person << " (Volwassen: " << volwassen << ", Internet: " << internet << ")\n";
    }
}
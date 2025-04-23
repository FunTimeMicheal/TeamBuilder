#include <iostream>
#include "MakeGroups.h"
#include "List.h"
#include "Add.h"
#include "Remove.h"


int main_loop() {
    std::string command, input, name, internet, volwassen;
    std::cout << "Voer een commando in (add, remove, list, exit, groups): ";

    while (true) {
        std::cin >> command;

        if (command == "exit") {
            break;
        } 
        else if (command == "add") {
            std::cout << "Voer een naam in: ";
            std::cin >> name;
            std::cout << "Volwassen of kind: V of K? ";
            std::cin >> volwassen;
            while (volwassen.size() > 1 || (volwassen != "v" && volwassen != "k")) {
                std::cout << "Volwassen of kind: V or K? ";
                std::cin >> volwassen;
            }

            std::cout << "Heeft internet: Y/N? ";
            std::cin >> internet;
            while (internet.size() > 1 || (internet != "y" && internet != "n")) {
                std::cout << "Heeft internet: Y or N? ";
                std::cin >> internet;
            }
            Add::add(name, volwassen, internet);
        } 
        else if (command == "remove") {
            std::cout << "Voer een naam in: ";
            std::cin >> input;
            Remove::remove(input);
        } 
        else if (command == "list") {
            List::list();
        } 
        else if (command == "groups") {
            int groepen = 0;
            std::cout << "Hoeveel groepen? ";
            std::cin >> groepen;
            if (groepen >= 1 && groepen <= 9) {
                std::cout << "Momentje geduld a.u.b., groepen worden gemaakt.\n";
                MakeGroups::makegroup(groepen);
            } else {
                std::cout << "Ongeldige invoer, geef een getal tussen 1 en 9 op.\n";
            }
        } 
        else {
            std::cout << "Ongeldig commando.\n";
        }

        std::cout << "Voer een commando in (add, remove, list, exit, groups): ";
    }
    return 0;
}
 
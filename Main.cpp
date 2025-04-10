#include <iostream>
#include <vector>
#include <map>
#include <bits/algorithmfwd.h>
#include <random>
#include <algorithm>  
#include "DataBase.h"
#include "sqlite3.h"




class NameManager {
public:
    static void add(std::string person, std::string volwassen, std::string internet);
    static void remove(std::string person);
    static void list();
    static void makegroup(int groepen);

private:
    static std::map<std::string, std::pair<std::string, std::string>> Names;
    
};

std::map<std::string, std::pair<std::string, std::string>> NameManager::Names;

void NameManager::add(std::string person, std::string volwassen, std::string internet) {
    Names[person] = {volwassen, internet}; 
    std::cout << "Toegevoegd: " << person << " (Volwassen: " << volwassen << ", Internet: " << internet << ")\n";
}

void NameManager::remove(std::string person) {
    auto it = Names.find(person); 
    if (it != Names.end()) {
        Names.erase(it);  
        std::cout << "Verwijderd: " << person << "\n";
    } else {
        std::cout << "Naam niet gevonden: " << person << "\n";
    }
}

void NameManager::list() {
    if (Names.empty()) {
        std::cout << "Geen namen opgeslagen.\n";
    } else {
        std::cout << "Opgeslagen namen:\n";
        for (const auto& entry : Names) {
            std::cout << "- " << entry.first << " (Volwassen: " << entry.second.first << ", Internet: " << entry.second.second << ")\n";
        }
    }
}

void NameManager::makegroup(int groepen) {
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::vector<std::vector<std::string>> team(groepen);
    std::vector<std::vector<std::string>> deelnemers;

    for (size_t i = 0; i < deelnemers.size(); i++)
    {
        deelnemers[i].clear();
    }
    
    for (const auto& entry : Names) {
        if(entry.second.second == "y")
            deelnemers[0].push_back(entry.first);
        if (entry.second.second == "n" && entry.second.first == "v")
            deelnemers[1].push_back(entry.first);
        else
            deelnemers[2].push_back(entry.first);
    }

    if (deelnemers[0].size() < groepen) {
        std::cout << "Er zijn niet genoeg deelnemers voor " << groepen << " groepen.\n";
        return;
    }

    for (size_t i = 0; i < deelnemers.size(); i++)
    {
        std::shuffle(deelnemers[i].begin(), deelnemers[i].end(), rng);
    }
    
    for (size_t i = 0; i < deelnemers[0].size(); ++i) {
        team[i % groepen].push_back(deelnemers[0][i]);
    }
    for (size_t i = 0; i < deelnemers[1].size(); ++i) {
        team[i % groepen].push_back(deelnemers[1][i]);
    }
    for (size_t i = 0; i < deelnemers[2].size(); ++i) {
        team[i % groepen].push_back(deelnemers[2][i]);
    }
    
    for (int i = 0; i < groepen; ++i) {
        std::cout << "Groep " << i + 1 << ": ";
        for (const auto& deelnemer : team[i]) {
            std::cout << deelnemer << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    open_db();  // Verbinding maken met de database
    std::cout << "Database actief";
    create_table();  // Tabel aanmaken als die nog niet bestaat

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
            NameManager::add(name, volwassen, internet);
        } 
        else if (command == "remove") {
            std::cout << "Voer een naam in: ";
            std::cin >> input;
            NameManager::remove(input);
        } 
        else if (command == "list") {
            NameManager::list();
        } 
        else if (command == "groups") {
            int groepen = 0;
            std::cout << "Hoeveel groepen? ";
            std::cin >> groepen;
            if (groepen >= 1 && groepen <= 9) {
                std::cout << "Momentje geduld a.u.b., groepen worden gemaakt.\n";
                NameManager::makegroup(groepen);
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

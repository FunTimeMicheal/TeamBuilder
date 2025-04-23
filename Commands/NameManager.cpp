#include <iostream>
#include <vector>
#include <map>
#include <bits/algorithmfwd.h>
#include <random>
#include <algorithm>  

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
    
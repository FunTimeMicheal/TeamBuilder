#include "MakeGroups.h"
#include <random>
#include <algorithm>  
#include <bits/algorithmfwd.h>
#include <iostream>

class  MakeGroups
{
    void MakeGroups::makegroup(int groepen) {
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

        for (size_t j =0; j < 2; j++)
        {
            for (size_t i = 0; i < deelnemers[j].size(); ++i) {
                team[i % groepen].push_back(deelnemers[j][i]);
            }
        }
        
        for (int i = 0; i < groepen; ++i) {
            std::cout << "Groep " << i + 1 << ": ";
            for (const auto& deelnemer : team[i]) {
                std::cout << deelnemer << " ";
            }
            std::cout << std::endl;
        }
    }

    void MakeGroups::~makegroup(){
        
    }

};

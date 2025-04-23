#ifndef MAKEGROUPS_H
#define MAKEGROUPS_H

#include <vector>


class MakeGroups
{
    public:
        MakeGroups::MakeGroups();
        MakeGroups::~MakeGroups();
        static void MakeGroups::makegroup(int);
    
    private:
        std::vector<std::vector<std::string>> team(int);
        std::vector<std::vector<std::string>> deelnemers;

};

#endif
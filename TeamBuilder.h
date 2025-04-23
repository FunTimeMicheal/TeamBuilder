#ifndef TEAMBUILDER_H
#define TEAMBUILDER_H


#include <map>
#include <string>

class TeamBuilder
{
private:
    /* data */

public:
    TeamBuilder();
    ~TeamBuilder();

    static std::map<std::string, std::pair<std::string, std::string>> Names;
};

#endif
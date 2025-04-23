#include "List.h"
#include <iostream>

class List
{
private:
    /* data */
public:
    List(/* args */);
    ~List();
};

void List::list() {
    if (Names.empty()) {
        std::cout << "Geen namen opgeslagen.\n";
    } else {
        std::cout << "Opgeslagen namen:\n";
        for (const auto& entry : Names) {
            std::cout << "- " << entry.first << " (Volwassen: " << entry.second.first << ", Internet: " << entry.second.second << ")\n";
        }
    }
}

List::~List()
{
}

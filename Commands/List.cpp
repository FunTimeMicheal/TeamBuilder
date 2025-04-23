#include "List.h"
#include <iostream>
#include "TeamBuilder.h"
List::List(){
}
List::~List(){
}

void List::list() {
    if (TeamBuilder::Names.empty()) {
        std::cout << "Geen namen opgeslagen.\n";
    } else {
        std::cout << "Opgeslagen namen:\n";
        for (const auto& entry : TeamBuilder::Names) {
            std::cout << "- " << entry.first << " (Volwassen: " << entry.second.first << ", Internet: " << entry.second.second << ")\n";
        }
    }
}



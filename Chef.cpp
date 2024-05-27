#include "Chef.h"
#include <iostream>

Chef::Chef(int id, const std::string& name) : User(id, name) {}

void Chef::displayMenu() const {
    std::cout << "Chef Menu: \n"
              << "1. Browse Raw Materials\n"
              << "2. Edit Menu\n";
}

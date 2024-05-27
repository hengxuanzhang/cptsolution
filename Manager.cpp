#include "Manager.h"
#include <iostream>

Manager::Manager(int id, const std::string& name) : User(id, name) {}

void Manager::displayMenu() const {
    std::cout << "Manager Menu: \n"
              << "1. Add Raw Material\n"
              << "2. Modify Raw Material\n"
              << "3. Delete Raw Material\n"
              << "4. Add Dish\n"
              << "5. Modify Dish\n"
              << "6. Delete Dish\n"
              << "7. View Customers\n"
              << "8. Calculate Profit\n";
}

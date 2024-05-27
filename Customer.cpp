#include "Customer.h"
#include <iostream>

Customer::Customer(int id, const std::string& name) : User(id, name) {}

void Customer::displayMenu() const {
    std::cout << "Customer Menu: \n"
              << "1. Browse Menu\n"
              << "2. Order Dishes\n"
              << "3. Check-out\n";
}

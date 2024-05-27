#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"

class Customer : public User {
public:
    Customer(int id, const std::string& name);
    std::string userCategory() const override { return "Customer"; }
    void displayMenu() const override;
};

#endif // CUSTOMER_H

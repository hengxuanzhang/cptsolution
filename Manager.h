#ifndef MANAGER_H
#define MANAGER_H

#include "User.h"

class Manager : public User {
public:
    Manager(int id, const std::string& name);
    std::string userCategory() const override { return "Manager"; }
};

#endif // MANAGER_H

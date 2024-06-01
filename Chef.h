#ifndef CHEF_H
#define CHEF_H

#include "User.h"

class Chef : public User {
public:
    Chef(int id, const std::string& name);
    std::string userCategory() const override { return "Chef"; }
};

#endif // CHEF_H

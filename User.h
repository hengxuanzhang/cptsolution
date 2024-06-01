#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

class User {
protected:
    int id;
    std::string name;

public:
    User(int id, const std::string& name);
    virtual ~User() = default;
    virtual std::string userCategory() const { return "User"; }
    int getId() const { return this->id; }
    std::string getName() const { return this->name; }
    void setName(std::string username) { this->name = username; };
    void display() const {
        std::cout << userCategory() << id << ": " << name << std::endl;
    }
};

#endif // USER_H

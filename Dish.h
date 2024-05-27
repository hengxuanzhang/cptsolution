#ifndef DISH_H
#define DISH_H

#include <string>
#include <vector>
#include <iostream>

class Dish {
private:
    int id;
    std::string name;
    double price;
    std::vector<int> rawMaterialIds;
    std::vector<std::string> ingredients;

public:
    Dish(int id, const std::string& name, double price, const std::vector<int>& rawMaterialIds);
    virtual ~Dish() = default;
    int getId() const;
    const std::string& getName() const;
    double getPrice() const;
    void setPrice(double price);
    const std::vector<int>& getRawMaterialIds() const;
    void display() const {
        std::cout << "Dish: " << name << ", Ingredients: ";
        for (const auto& ingredient : ingredients) {
            std::cout << ingredient << " ";
        }
        std::cout << ", Price: $" << price << std::endl;
    }
};

#endif // DISH_H

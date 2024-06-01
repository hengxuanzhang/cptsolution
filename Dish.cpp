#include "Dish.h"

Dish::Dish(int id, const std::string &name, double price, const std::vector<int> &rawMaterialIds)
    : id(id), name(name), price(price), rawMaterialIds(rawMaterialIds)  {}

int Dish::getId() const { return id; }
const std::string& Dish::getName() const { return name; }
double Dish::getPrice() const { return price; }
void Dish::setPrice(double price) { this->price = price; }
const std::vector<int>& Dish::getRawMaterialIds() const { return rawMaterialIds; }
void Dish::display() const {
    std::cout << id << ": " << name << ", Raw Material Ids:";
    for (int num : rawMaterialIds) {
        std::cout << num << ",";
    }
    std::cout << " Price:$" << price << std::endl;
}

#include "Dish.h"

Dish::Dish(int id, const std::string &name, double price, const std::vector<int> &rawMaterialIds)
    : name(name), price(price)  {}
int Dish::getId() const { return id; }
const std::string& Dish::getName() const { return name; }
double Dish::getPrice() const { return price; }
void Dish::setPrice(double price) { this->price = price; }
const std::vector<int>& Dish::getRawMaterialIds() const { return rawMaterialIds; }

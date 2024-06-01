#include "RawMaterial.h"

RawMaterial::RawMaterial(int id, const std::string& name, double price, int quantity)
        : id(id), name(name), price(price), quantity(quantity) {}

int RawMaterial::getId() const { return id; }
const std::string & RawMaterial::getName() const { return name; }
double RawMaterial::getPrice() const { return price; }
int RawMaterial::getQuantity() const { return quantity; }
void RawMaterial::setPrice(double price) { this->price = price; }
void RawMaterial::setQuantity(int quantity) { this->quantity = quantity; }
void RawMaterial::display() const {
    std::cout << id << ": " << this->name << ", Price: " << this->price << ", Quantity: " << this->quantity << std::endl;
}

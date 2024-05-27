#ifndef RAWMATERIAL_H
#define RAWMATERIAL_H

#include <string>
#include <iostream>

class RawMaterial {
private:
    int id;
    std::string name;
    double price;
    int quantity;

public:
    RawMaterial(int id, const std::string& name, double price, int quantity);
    virtual ~RawMaterial() = default;
    int getId() const;
    const std::string & getName() const;
    double getPrice() const;
    int getQuantity() const;
    void setPrice(double price);
    void setQuantity(int quantity);
    void display() const;
};

#endif // RAWMATERIAL_H

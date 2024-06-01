#ifndef RESTAURANTMANAGEMENTSYSTEM_H
#define RESTAURANTMANAGEMENTSYSTEM_H

#include "Manager.h"
#include "Chef.h"
#include "User.h"
#include "Customer.h"
#include "RawMaterial.h"
#include "Dish.h"
#include <vector>
#include <memory>

class RestaurantManagementSystem {
private:
    std::vector<RawMaterial> rawMaterials;
    std::vector<Dish> dishes;
    std::vector<Dish> ordered_dishes;
    std::vector<Customer> customers;
    std::vector<std::shared_ptr<User>> users;

public:
    RestaurantManagementSystem();
    std::string findUserCategory(std::string& username, std::vector<std::shared_ptr<User>>& users);
    void managerMenu();
    void chefMenu();
    void customerMenu();
    void showAllCustomers() const;
    void showAllRawMaterials() const;
    void showAllDishes() const;
    void addCustomer(const Customer& customer);
    void addRawMaterial(const RawMaterial& material);
    void addDish(const Dish& dish);
    void deleteCustomer(int id, std::string username);
    void deleteRawMaterial(const std::string& name);
    void deleteDish(int id);
    void modifyCustomer(int id, std::string username);
    void modifyRawMaterial(const std::string& name, int newQuantity);
    void modifyDish(int id, double newPrice);

    bool isDishIdUnique(int id) const;
    bool isDishNameUnique(const std::string& name) const;
    void placeOrder(const std::vector<int>& order);
    void checkOut();
    void run();
};

#endif // RESTAURANTMANAGEMENTSYSTEM_H

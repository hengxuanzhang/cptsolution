#include "RestaurantManagementSystem.h"
#include <iostream>
#include <algorithm>
#include <memory>

// 构造函数
RestaurantManagementSystem::RestaurantManagementSystem() = default;

std::string RestaurantManagementSystem::findUserCategory(std::string& username, std::vector<std::shared_ptr<User>>& users) {
    for (const auto& user : users) {
        if (user->getName() == username) {
            return user->userCategory();
        }
    }
    std::cout << "User not found" << std::endl;
    return "";
}

// 显示所有顾客
void RestaurantManagementSystem::showAllCustomers() const {
    std::cout << "Users in the system:" << std::endl;
    for (const auto& user : users) {
        if (user->userCategory() == "Customer") {
            user->display();
        }
    }
}

// 显示所有原材料
void RestaurantManagementSystem::showAllRawMaterials() const {
    std::cout << "Raw materials in the inventory:" << std::endl;
    for (const auto& material : rawMaterials) {
        material.display();
    }
}

// 显示所有菜品
void RestaurantManagementSystem::showAllDishes() const {
    std::cout << "Dishes available in the menu:" << std::endl;
    for (const Dish& dish : dishes) {
        dish.display();
    }
}

void RestaurantManagementSystem::addCustomer(const Customer& customer) {
    users.push_back(std::make_shared<Customer>(customer.getId(), customer.getName()));
}

void RestaurantManagementSystem::addRawMaterial(const RawMaterial& material) {
    rawMaterials.push_back(material);
}

void RestaurantManagementSystem::addDish(const Dish& dish) {
    if (isDishIdUnique(dish.getId()) && isDishNameUnique(dish.getName())) {
        dishes.push_back(dish);
    } else {
        std::cout << "Dish ID or Name already exists." << std::endl;
    }
}

void RestaurantManagementSystem::deleteCustomer(int id, std::string username) {
    // lambda函数, 传入 id,username 并判断, 将 return true 的元素移动到容器的末尾并删除
    auto new_end = std::remove_if(users.begin(), users.end(),
                                  [id, &username](const std::shared_ptr<User>& user) {
                                      return user->getId() == id && user->getName() == username;
                                  });

    users.resize(std::distance(users.begin(), new_end));
}

void RestaurantManagementSystem::deleteRawMaterial(const std::string& name) {
    // 将所有外部变量"[&]"传参给 lambda 函数并判断, 将 return true 的元素移动到容器的末尾并删除
    rawMaterials.erase(std::remove_if(rawMaterials.begin(), rawMaterials.end(),
                                      [&](const RawMaterial& material) { return material.getName() == name; }),
                       rawMaterials.end());
}

void RestaurantManagementSystem::deleteDish(int id) {
    dishes.erase(std::remove_if(dishes.begin(), dishes.end(),
                                [&](const Dish& dish) { return dish.getId() == id; }),
                 dishes.end());
}

void RestaurantManagementSystem::modifyCustomer(int id, std::string username) {
    for (auto& user : users) {
        if (user->getId() == id && user->userCategory() == "customer") {
            user->setName(username);
            break;
        }
    }
}

void RestaurantManagementSystem::modifyRawMaterial(const std::string& name, int newQuantity) {
    for (auto& material : rawMaterials) {
        if (material.getName() == name) {
            material.setQuantity(newQuantity);
            break;
        }
    }
}

void RestaurantManagementSystem::modifyDish(int id, double newPrice) {
    for (auto& dish : dishes) {
        if (dish.getId() == id) {
            dish.setPrice(newPrice);
            break;
        }
    }
}

bool RestaurantManagementSystem::isDishIdUnique(int id) const {
    return std::none_of(dishes.begin(), dishes.end(), [&](const Dish& dish) { return dish.getId() == id; });
}

bool RestaurantManagementSystem::isDishNameUnique(const std::string& name) const {
    return std::none_of(dishes.begin(), dishes.end(), [&](const Dish& dish) { return dish.getName() == name; });
}

void RestaurantManagementSystem::placeOrder(const std::vector<int>& order) {
    // 实现下订单的逻辑
}

void RestaurantManagementSystem::checkOut() {
    // 实现结账的逻辑
}

void RestaurantManagementSystem::managerMenu() {
    int choice;
    do {
        std::cout << "\nManager Menu:\n";
        std::cout << "1. Browse Customers\n";
        std::cout << "2. Add Customers\n";
        std::cout << "3. Modify Customers\n";
        std::cout << "4. Delete Customers\n";
        std::cout << "5. Browse Raw Materials\n";
        std::cout << "6. Add Raw Material\n";
        std::cout << "7. Modify Raw Material\n";
        std::cout << "8. Delete Raw Material\n";
        std::cout << "9. Browse Dishes\n";
        std::cout << "10. Add Dish\n";
        std::cout << "11. Modify Dish\n";
        std::cout << "12. Delete Dish\n";
        std::cout << "13. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                showAllCustomers();
                break;
            case 2: {
                std::string name;
                int quantity;
                int id = 4;
                double price;
                std::cout << "Enter raw material name: ";
                std::cin >> name;
                std::cout << "Enter id: ";
                std::cin >> id;
                addCustomer(Customer(id, name));
                break;
            }
            case 3: {
                int id;
                std::string name;
                std::cout << "Enter customer id: ";
                std::cin >> id;
                std::cout << "Enter customer name: ";
                std::cin >> name;
                modifyCustomer(id, name);
                break;
            }
            case 4: {
                int id;
                std::string name;
                std::cout << "Enter customer id: ";
                std::cin >> id;
                std::cout << "Enter customer name: ";
                std::cin >> name;
                deleteCustomer(id, name);
                break;
            }
            case 5:
                showAllRawMaterials();
                break;
            case 6: {
                std::string name;
                int quantity;
                int id = 4;
                double price;
                std::cout << "Enter raw material name: ";
                std::cin >> name;
                std::cout << "Enter id: ";
                std::cin >> id;
                std::cout << "Enter price: ";
                std::cin >> price;
                std::cout << "Enter quantity: ";
                std::cin >> quantity;
                addRawMaterial(RawMaterial(id, name, price, quantity));
                break;
            }
            case 7: {
                std::string name;
                int newQuantity;
                std::cout << "Enter raw material name: ";
                std::cin >> name;
                std::cout << "Enter new quantity: ";
                std::cin >> newQuantity;
                modifyRawMaterial(name, newQuantity);
                break;
            }
            case 8: {
                std::string name;
                std::cout << "Enter raw material name: ";
                std::cin >> name;
                deleteRawMaterial(name);
                break;
            }
            case 9:
                showAllDishes();
                break;
            case 10: {
                int id;
                std::string name;
                std::vector<int> ingredients;
                int ingredient;
                double price;
                std::cout << "Enter dish ID: ";
                std::cin >> id;
                std::cout << "Enter dish name: ";
                std::cin >> name;
                std::cout << "Enter ingredients (end with '0'): ";
                while (true) {
                    std::cin >> ingredient;
                    if (ingredient == 0) break;
                    ingredients.push_back(ingredient);
                }
                std::cout << "Enter price: ";
                std::cin >> price;
                addDish(Dish(id, name, price, ingredients));
                break;
            }
            case 11: {
                int id;
                double newPrice;
                std::cout << "Enter dish ID: ";
                std::cin >> id;
                std::cout << "Enter new price: ";
                std::cin >> newPrice;
                modifyDish(id, newPrice);
                break;
            }
            case 12: {
                int id;
                std::cout << "Enter dish ID: ";
                std::cin >> id;
                deleteDish(id);
                break;
            }
            case 13:
                std::cout << "Exiting Manager Menu.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 9);
}

void RestaurantManagementSystem::chefMenu() {
    int choice;
    do {
        std::cout << "\nChef Menu:\n";
        std::cout << "1. Browse Raw Materials\n";
        std::cout << "2. Add Raw Material\n";
        std::cout << "3. Modify Raw Material\n";
        std::cout << "4. Delete Raw Material\n";
        std::cout << "5. Browse Dishes\n";
        std::cout << "6. Add Dish\n";
        std::cout << "7. Modify Dish\n";
        std::cout << "8. Delete Dish\n";
        std::cout << "9. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                showAllRawMaterials();
                break;
            case 2: {
                std::string name;
                int quantity;
                int id = 4;
                double price;
                std::cout << "Enter raw material name: ";
                std::cin >> name;
                std::cout << "Enter id: ";
                std::cin >> id;
                std::cout << "Enter price: ";
                std::cin >> price;
                std::cout << "Enter quantity: ";
                std::cin >> quantity;
                addRawMaterial(RawMaterial(id, name, price, quantity));
                break;
            }
            case 3: {
                std::string name;
                int newQuantity;
                std::cout << "Enter raw material name: ";
                std::cin >> name;
                std::cout << "Enter new quantity: ";
                std::cin >> newQuantity;
                modifyRawMaterial(name, newQuantity);
                break;
            }
            case 4: {
                std::string name;
                std::cout << "Enter raw material name: ";
                std::cin >> name;
                deleteRawMaterial(name);
                break;
            }
            case 5:
                showAllDishes();
                break;
            case 6: {
                int id;
                std::string name;
                std::vector<int> ingredients;
                int ingredient;
                double price;
                std::cout << "Enter dish ID: ";
                std::cin >> id;
                std::cout << "Enter dish name: ";
                std::cin >> name;
                std::cout << "Enter ingredients (end with '0'): ";
                while (true) {
                    std::cin >> ingredient;
                    if (ingredient == 0) break;
                    ingredients.push_back(ingredient);
                }
                std::cout << "Enter price: ";
                std::cin >> price;
                addDish(Dish(id, name, price, ingredients));
                break;
            }
            case 7: {
                int id;
                double newPrice;
                std::cout << "Enter dish ID: ";
                std::cin >> id;
                std::cout << "Enter new price: ";
                std::cin >> newPrice;
                modifyDish(id, newPrice);
                break;
            }
            case 8: {
                int id;
                std::cout << "Enter dish ID: ";
                std::cin >> id;
                deleteDish(id);
                break;
            }
            case 9:
                std::cout << "Exiting Chef Menu.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 9);
}

void RestaurantManagementSystem::customerMenu() {
    int choice;
    do {
        std::cout << "\nCustomer Menu:\n";
        std::cout << "1. Browse Menu\n";
        std::cout << "2. Order Dishes\n";
        std::cout << "3. Check-out\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                showAllDishes();
                break;
            case 2: {
                std::vector<int> order;
                int id;
                std::cout << "Enter dish IDs to order (end with -1): ";
                while (true) {
                    std::cin >> id;
                    if (id == -1) break;
                    order.push_back(id);
                }
                // 此处假设存在下单的方法, 可以进一步实现该功能
                placeOrder(order);
                std::cout << "Order placed successfully.\n";
                break;
            }
            case 3:
                // 此处假设存在结账的方法, 可以进一步实现该功能
                checkOut();
                std::cout << "Check-out successful.\n";
                break;
            case 4:
                std::cout << "Exiting Customer Menu.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}

// 主运行逻辑
void RestaurantManagementSystem::run() {
    // 初始化系统用户和顾客
    users.push_back(std::make_shared<Manager>(1, "Manager1"));
    users.push_back(std::make_shared<Chef>(1, "Gu"));
    users.push_back(std::make_shared<Chef>(2, "Liu"));
    users.push_back(std::make_shared<Customer>(1, "Gang"));
    users.push_back(std::make_shared<Customer>(2, "Ming"));
    users.push_back(std::make_shared<Customer>(3, "Wang"));

    // 初始化原材料
    rawMaterials.emplace_back(1, "Tomato", 100.0, 10);
    rawMaterials.emplace_back(2, "Cheese", 50.0, 20);
    rawMaterials.emplace_back(3, "Dough", 30.0, 15);

    // 初始化菜品
    dishes.emplace_back(1, "Pizza", 30.0, std::vector<int>{3, 1, 2});
    dishes.emplace_back(2, "Salad", 40.0, std::vector<int>{1, 2});

    std::string username;
    std::cout << "Enter username: ";
    std::cin >> username;

    std::string category = findUserCategory(username, users);
    int role = 0;
    if (category.empty()) {
        role = 0;
    }
    if (category == "Manager") {
        role = 1;
    }
    else if (category == "Chef") {
        role = 2;
    }
    else if (category == "Customer") {
        role = 3;
    }

    switch (role) {
        case 1:
            managerMenu();
            break;
        case 2:
            chefMenu();
            break;
        case 3:
            customerMenu();
            break;
        default:
            break;
    }
}
cmake_minimum_required(VERSION 3.10)

# Project name
project(RestaurantManagementSystem VERSION 1.0)

# C++ standard: C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR})

# Source files
set(SOURCES
        main.cpp
        RestaurantManagementSystem.cpp
        User.cpp
        Manager.cpp
        Chef.cpp
        Customer.cpp
        RawMaterial.cpp
        Dish.cpp
)

# Head files
set(HEADERS
        RestaurantManagementSystem.h
        User.h
        Manager.h
        Chef.h
        Customer.h
        RawMaterial.h
        Dish.h
)

add_executable(RestaurantManagementSystem ${SOURCES} ${HEADERS})

# Enable debug and release mode
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(RestaurantManagementSystem PRIVATE -g)
else()
    target_compile_options(RestaurantManagementSystem PRIVATE -O3)
endif()

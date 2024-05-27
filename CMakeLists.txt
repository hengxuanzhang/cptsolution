cmake_minimum_required(VERSION 3.10)

# 项目名称和版本
project(RestaurantManagementSystem VERSION 1.0)

# 设置语言标准为 C++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加头文件目录
include_directories(${PROJECT_SOURCE_DIR})

# 源文件列表
set(SOURCES
        main.cpp
        RestaurantManagementSystem.cpp
        User.cpp
        Manager.cpp
        Chef.cpp
        Customer.cpp
        RawMaterial.cpp
        Dish.cpp
        Utils.cpp
)

# 头文件列表
set(HEADERS
        RestaurantManagementSystem.h
        User.h
        Manager.h
        Chef.h
        Customer.h
        RawMaterial.h
        Dish.h
        Utils.h
)

# 添加可执行文件
add_executable(RestaurantManagementSystem ${SOURCES} ${HEADERS})

# 为Debug和Release模式添加编译选项
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(RestaurantManagementSystem PRIVATE -g)
else()
    target_compile_options(RestaurantManagementSystem PRIVATE -O3)
endif()

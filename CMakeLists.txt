cmake_minimum_required(VERSION 3.27)
project(2)

set(CMAKE_CXX_STANDARD 17)

add_executable(2 main.cpp
        Product.h
        Product.cpp
        Customer.h
        Customer.cpp
        Store.cpp
        Store.h
        Basket.h
        Person.h
        Person.cpp
        OnlineBasket.h
        Basket.cpp
        Admin.h
        Admin.cpp
)

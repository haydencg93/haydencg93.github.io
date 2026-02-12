cmake_minimum_required(VERSION 3.26)
project(hw6)

set(CMAKE_CXX_STANDARD 17)

add_executable(hw6 main.cpp
        Item.cpp
        Item.h
        Book.cpp
        Book.h
        Audiobook.cpp
        Audiobook.h
        Magazine.cpp
        Magazine.h)
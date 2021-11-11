cmake_minimum_required(VERSION 3.20)
project(lab4)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES main.cpp
            GroupOfShips/Person/Person.cpp
            GroupOfShips/Weapon/Weapon.cpp)

include_directories(
        GroupOfShips
        GroupOfShips/Person
        GroupOfShips/Weapon)

add_executable(lab4 ${SOURCES})

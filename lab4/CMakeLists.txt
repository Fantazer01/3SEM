cmake_minimum_required(VERSION 3.20)
project(lab4)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
        main.cpp
        GroupOfShips/Person/Person.cpp
        GroupOfShips/Weapon/Weapon.cpp
        GroupOfShips/Plane/Plane.cpp
        GroupOfShips/Ship/Ship.cpp
        GroupOfShips/AircraftCarrier/AircraftCarrier.cpp)

include_directories(
        GroupOfShips
        GroupOfShips/Person
        GroupOfShips/Weapon
        GroupOfShips/Plane
        GroupOfShips/Ship
        GroupOfShips/AircraftCarrier)

add_executable(lab4 ${SOURCES})

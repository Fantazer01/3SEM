cmake_minimum_required(VERSION 3.20)
project(GroupOfShips)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
        Person/Person.cpp
        Weapon/Weapon.cpp
        Plane/Plane.cpp
        AircraftCarrier/AircraftCarrier.cpp
        Destroyer/Destroyer.cpp
        Ship/Ship.cpp
        TableOfShips/TableOfShips.cpp
        GroupOfShips/GroupOfShips.cpp
        GroupOfShips/groupAiming.cpp
        GroupOfShips/enemyAiming.cpp
        GroupOfShips/decreaseHealth.cpp
        )

include_directories(
        Person
        Weapon
        Plane
        Ship
        AircraftCarrier
        Destroyer
        TableOfShips
        GroupOfShips)

add_library(${PROJECT_NAME} STATIC ${SOURCES})
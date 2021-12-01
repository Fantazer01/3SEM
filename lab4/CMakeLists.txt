cmake_minimum_required(VERSION 3.20)
project(lab4)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
        main.cpp
        GroupOfShips/Person/Person.cpp
        GroupOfShips/Weapon/Weapon.cpp
        GroupOfShips/Plane/Plane.cpp
        GroupOfShips/Ship/Ship.cpp
        GroupOfShips/AircraftCarrier/AircraftCarrier.cpp
        GroupOfShips/Destroyer/Destroyer.cpp
        GroupOfShips/TableOfShips/TableOfShips.cpp
        GroupOfShips/GroupOfShips/GroupOfShips.cpp)

include_directories(
        GroupOfShips
        GroupOfShips/Person
        GroupOfShips/Weapon
        GroupOfShips/Plane
        GroupOfShips/Ship
        GroupOfShips/AircraftCarrier
        GroupOfShips/Destroyer
        GroupOfShips/TableOfShips
        GroupOfShips/GroupOfShips)

add_subdirectory(GroupOfShips/Person)
add_subdirectory(GroupOfShips/Weapon)
add_subdirectory(GroupOfShips/Plane)
add_subdirectory(GroupOfShips/Ship)
add_subdirectory(GroupOfShips/AircraftCarrier)
add_subdirectory(GroupOfShips/Destroyer)

add_executable(lab4 ${SOURCES})

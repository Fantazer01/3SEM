cmake_minimum_required(VERSION 3.20)
project(testTableOfShips)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
        testTableOfShips.cpp
        ../Weapon/Weapon.cpp
        ../Person/Person.cpp
        ../Plane/Plane.cpp
        ../Ship/Ship.cpp
        ../AircraftCarrier/AircraftCarrier.cpp
        ../Destroyer/Destroyer.cpp
        TableOfShips.cpp)


add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} gtest gtest_main pthread)
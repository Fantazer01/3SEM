cmake_minimum_required(VERSION 3.20)
project(testGroupOfShips)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
        testGroupOfShips.cpp
        ../Weapon/Weapon.cpp
        ../Person/Person.cpp
        ../Plane/Plane.cpp
        ../Ship/Ship.cpp
        ../AircraftCarrier/AircraftCarrier.cpp
        ../Destroyer/Destroyer.cpp
        ../TableOfShips/TableOfShips.cpp
        GroupOfShips.cpp)


add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} gtest gtest_main pthread)
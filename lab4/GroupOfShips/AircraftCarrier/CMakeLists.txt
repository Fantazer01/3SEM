cmake_minimum_required(VERSION 3.20)
project(testAircraftCarrier)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
        testAircraftCarrier.cpp
        ../Weapon/Weapon.cpp
        ../Person/Person.cpp
        ../Plane/Plane.cpp
        ../Ship/Ship.cpp
        AircraftCarrier.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} gtest gtest_main pthread)

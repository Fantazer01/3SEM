cmake_minimum_required(VERSION 3.20)
project(testDestroyer)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
        testDestroyer.cpp
        ../Weapon/Weapon.cpp
        ../Person/Person.cpp
        ../Ship/Ship.cpp
        Destroyer.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} gtest gtest_main pthread)

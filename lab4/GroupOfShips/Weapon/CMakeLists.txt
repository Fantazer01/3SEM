cmake_minimum_required(VERSION 3.20)
project(testWeapon)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
        testWeapon.cpp
        Weapon.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} gtest gtest_main pthread)

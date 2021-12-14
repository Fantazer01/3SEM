cmake_minimum_required(VERSION 3.20)
project(testPair)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
        testPair.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} gtest gtest_main pthread)
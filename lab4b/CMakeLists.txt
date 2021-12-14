cmake_minimum_required(VERSION 3.20)
project(Templates)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
        )

include_directories(
        Templates/Pair
        Templates/Vector
        Templates/Map)

add_subdirectory(Templates/Pair/test)
add_subdirectory(Templates/Vector/test)
add_subdirectory(Templates/Map/test)

#add_executable(${PROJECT_NAME} ${SOURCES})

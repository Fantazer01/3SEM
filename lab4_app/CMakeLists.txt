cmake_minimum_required(VERSION 3.20)
project(lab4_app)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
        src/main.cpp
        src/Initialize.cpp
        src/SelectPoint.cpp
        src/PutInformation.cpp
        src/GameProcess.cpp
        src/LabTools.cpp
        )

include_directories(include)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/lib/libGroupOfShips.a)

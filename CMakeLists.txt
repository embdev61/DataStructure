cmake_minimum_required(VERSION 3.10)

# Project name
project(DataStructuresWorkspace)

# Set C Standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Source files
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.c)

# Create an executable
add_executable(data_structures ${SOURCES})

cmake_minimum_required(VERSION 3.10)

# Project name
project(DataStructuresWorkspace)

# Set C Standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/config)


# Source files
file(GLOB SRC_FILES  ${PROJECT_SOURCE_DIR}/src/*.c)
file(GLOB LINKLIST_FILES  ${PROJECT_SOURCE_DIR}/linklistOps/*.c)

# Combine source files
set(SOURCES ${SRC_FILES} ${LINKLIST_FILES})
#set(SOURCES ${SRC_FILES})


# Create an executable
add_executable(data_structures ${SOURCES})

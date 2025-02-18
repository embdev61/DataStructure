cmake_minimum_required(VERSION 3.10)

# Project name
project(DataStructuresWorkspace)

# Set C Standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/config)
include_directories(${CMAKE_CURRENT_BINARY_DIR}) # Include the binary directory for config.h


# Source files
file(GLOB SRC_FILES  ${PROJECT_SOURCE_DIR}/src/*.c)
file(GLOB LINKLIST_FILES  ${PROJECT_SOURCE_DIR}/linklistOps/*.c)
file(GLOB CONFIG_FILES ${PROJECT_SOURCE_DIR}/config/config.c)

# Combine source files
set(SOURCES ${SRC_FILES} ${LINKLIST_FILES} ${CONFIG_FILES})
#set(SOURCES ${SRC_FILES})

# Set the base path environment variable
#set(BASE_PATH_ENV "${PROJECT_SOURCE_DIR}")
#message("BASE_PATH_ENV set to ${BASE_PATH_ENV}")

#set(BASE_PATH_ENV "C:\\AmitWorkspace")
#add_definitions(-DBASE_PATH="${BASE_PATH_ENV}")

# Create a configuration header file
#configure_file(
 #   ${CMAKE_CURRENT_SOURCE_DIR}/config_env.h.in
 #   ${CMAKE_CURRENT_BINARY_DIR}/config_env.h
 #   @ONLY
#)

set(BASE_PATH_ENV "${PROJECT_SOURCE_DIR}")
set(BASE_PATH "${BASE_PATH_ENV}")  # Ensure substitution variable is defined
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/config_env.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/config_env.h
    @ONLY
)


# Create an executable
add_executable(data_structures ${SOURCES})

#ifndef CONFIG_H
#define CONFIG_H

#include <string.h>

#define RESET   "\x1b[0m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1b[37m"

#define TRUE  1
#define FALSE 0

// Declaration only
const char *get_relative_path(const char *file);

// Macro to get the relative path
#define RELATIVE_PATH(file) (get_relative_path(file))

// Enhanced LOG macro to include relative file path and line number
#define LOG(level, color, fmt, ...) printf(color level ": [File: %s][Line %d] " fmt RESET "\n", RELATIVE_PATH(__FILE__), __LINE__, ##__VA_ARGS__)

#define ENABLE_PROCESS  TRUE
#define DISABLE_PROCESS FALSE

#define DEBUG_LOG            TRUE
#define MAX_LINKED_LIST_NODE 10

#define PROCESS_LINKED_LIST ENABLE_PROCESS
#define PROCESS_STACK       DISABLE_PROCESS
#define PROCESS_QUEUE       DISABLE_PROCESS
#define PROCESS_TREE        DISABLE_PROCESS
#define PROCESS_GRAPH       DISABLE_PROCESS

typedef int ListDataType;

#endif
#include "config.h"
#include "config_env.h"

const char *get_relative_path(const char *file) {
    char normalized_path[512];
    strcpy(normalized_path, file);

    // Normalize backslashes to forward slashes for consistent comparison
    for (int i = 0; normalized_path[i]; i++) {
        if (normalized_path[i] == '\\') {
            normalized_path[i] = '/';
        }
    }

    // Normalize BASE_PATH in a similar way
    char normalized_base_path[512];
    strcpy(normalized_base_path, BASE_PATH);
    for (int i = 0; normalized_base_path[i]; i++) {
        if (normalized_base_path[i] == '\\') {
            normalized_base_path[i] = '/';
        }
    }

    // Search for the normalized BASE_PATH
    char *relative_path = strstr(normalized_path, normalized_base_path);
    if (relative_path) {
        return file + (relative_path - normalized_path) + strlen(normalized_base_path) + 1;
    }

    return file;
}
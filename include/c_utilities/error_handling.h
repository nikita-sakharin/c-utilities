#ifndef C_UTILITIES_ERROR_HANDLING_H
#define C_UTILITIES_ERROR_HANDLING_H

#include <stdbool.h> // false
#include <stdio.h> // fprintf, perror, stderr
#include <stdlib.h> // EXIT_FAILURE, exit

// (condition) or condition ???
#define EXIT_IF(condition, message) \
    do { \
        if (condition) { \
            fprintf(stderr, "%s:%d: ", __FILE__, __LINE__); \
            perror(message); \
            exit(EXIT_FAILURE); \
        } \
    } while (false)

#define GOTO_IF(condition, label) \
    do { \
        if (condition) \
            goto label; \
    } while (false)

#endif // C_UTILITIES_ERROR_HANDLING_H

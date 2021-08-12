#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H

#include <stdio.h> // fprintf, perror, stderr
#include <stdlib.h> // EXIT_FAILURE, exit

// (condition) or condition ???
#define exit_if(condition, message) \
    do { \
        if (condition) { \
            fprintf(stderr, "%s:%d: ", __FILE__, __LINE__); \
            perror(message); \
            exit(EXIT_FAILURE); \
        } \
    } while (0)

#define goto_if(condition, label) \
    do { \
        if (condition) \
            goto label; \
    } while (0)

#endif

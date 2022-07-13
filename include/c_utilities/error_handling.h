#ifndef C_UTILITIES_ERROR_HANDLING_H
#define C_UTILITIES_ERROR_HANDLING_H

#include <stdbool.h> // false
#include <stdio.h> // fflush, fprintf, perror, stderr
#include <stdlib.h> // EXIT_FAILURE, abort, exit
#include <string.h> // strerror

#define ABORT_IF(condition) \
    do { \
        if ((condition)) { \
            fprintf(stderr, "%s:%d: ", __FILE__, __LINE__); /* error ??? */ \
            perror(__func__); \
            fflush(stderr); \
            abort(); \
        } \
    } while (false)

#define EXIT_IF(condition, argv0, error, ...) \
    do { \
        if ((condition)) { \
            fprintf(stderr, "%s: ", argv0); \
            fprintf(stderr, __VA_ARGS__); \
            fprintf(stderr, ": %s\n", strerror(error)); \
            exit(EXIT_FAILURE); \
        } \
    } while (false)

#ifdef NDEBUG
#define GOTO_IF(condition, label) \
    do { \
        if ((condition)) \
            goto label; \
    } while (false)
#else
#define GOTO_IF(condition, label) \
    do { \
        if ((condition)) { \
            fprintf(stderr, "%s:%d: ", __FILE__, __LINE__); /* error ??? */ \
            perror(__func__); \
            goto label; \
        } \
    } while (false)
#endif // NDEBUG
// WRITE_ERRNO_GOTO_IF

#endif // C_UTILITIES_ERROR_HANDLING_H

#ifndef C_UTILITIES_ERROR_HANDLING_H
#define C_UTILITIES_ERROR_HANDLING_H

#include <errno.h> // errno
#include <stdbool.h> // false
#include <stdio.h> // fflush, fprintf, perror, stderr
#include <stdlib.h> // EXIT_FAILURE, abort, exit
#include <string.h> // strerror

#define ABORT_IF(condition) \
    do { \
        if ((condition)) { \
            fprintf(stderr, "%s:%d: ", __FILE__, __LINE__); \
            perror(__func__); \
            fflush(stderr); \
            abort(); \
        } \
    } while (false)

#define EXIT_IF(condition, argv0, ...) \
    do { \
        if ((condition)) { \
            fprintf(stderr, "%s: ", argv0); \
            fprintf(stderr, __VA_ARGS__); \
            fprintf(stderr, ": %s\n", strerror(errno)); \
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
            fprintf(stderr, "%s:%d: ", __FILE__, __LINE__); \
            perror(__func__); \
            goto label; \
        } \
    } while (false)
#endif // NDEBUG

#endif // C_UTILITIES_ERROR_HANDLING_H

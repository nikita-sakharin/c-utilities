#ifndef C_UTILITIES_ERROR_HANDLING_H
#define C_UTILITIES_ERROR_HANDLING_H

#include <stdarg.h> // va_end, va_list, va_start
#include <stdbool.h> // false
#include <stdio.h> // fflush, fprintf, perror, stderr, vfprintf
#include <stdlib.h> // EXIT_FAILURE, abort, exit
#include <string.h> // strerror

#define ABORT_IF(condition, error) \
    do { \
        if ((condition)) { \
            fprintf(stderr, "%s:%d: %s: %s\n", \
                __FILE__, __LINE__, __func__, strerror(error) \
            ); \
            fflush(stderr); \
            abort(); \
        } \
    } while (false)

#define EXIT_IF(condition, error, argv0, ...) \
    do { \
        if ((condition)) { \
            printError(error, argv0, __VA_ARGS__); \
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

inline void printError(
    register const int error,
    register const char argv0[const static 1U],
    const char format[const static 1U],
    ...
) {
    fprintf(stderr, "%s: ", argv0);
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
    fprintf(stderr, ": %s\n", strerror(error));
}

#endif // C_UTILITIES_ERROR_HANDLING_H

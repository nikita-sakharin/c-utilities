#ifndef COMMON_H
#define COMMON_H

#include <inttypes.h> // imaxabs, imaxdiv
#include <stdint.h> // intmax_t, uintmax_t
#include <stdlib.h> // abs, div, labs, ldiv, llabs, lldiv

#include "types.h"

// TODO: include or in another one file
#define exit_if(condition, message) \
    do { \
        if (condition) { \
            fprintf(stderr, "%s:%d: ", __FILE__, __LINE__); \
            const char * const str = (message); \
            if (str != NULL && str[0] != '\0') \
                fprintf(stderr, "%s: ", str); \
            fprintf(stderr, "%s\n", strerror(errno)); \
            exit(EXIT_FAILURE); \
        } \
    } while (0)

#define goto_if(condition, label) \
    do { \
        if (condition) \
            goto label; \
    } while (0)

inline int max(register const int a, register const int b) {
    return a < b ? b : a;
}

inline uint umax(register const uint a, register const uint b) {
    return a < b ? b : a;
}

inline long lmax(register const long a, register const long b) {
    return a < b ? b : a;
}

inline ulong ulmax(register const ulong a, register const ulong b) {
    return a < b ? b : a;
}

inline llong llmax(register const llong a, register const llong b) {
    return a < b ? b : a;
}

inline ullong ullmax(register const ullong a, register const ullong b) {
    return a < b ? b : a;
}

inline intmax_t imaxmax(
    register const intmax_t a,
    register const intmax_t b
) {
    return a < b ? b : a;
}

inline uintmax_t umaxmax(
    register const uintmax_t a,
    register const uintmax_t b
) {
    return a < b ? b : a;
}

inline int min(register const int a, register const int b) {
    return b < a ? b : a;
}

inline uint umin(register const uint a, register const uint b) {
    return b < a ? b : a;
}

inline long lmin(register const long a, register const long b) {
    return b < a ? b : a;
}

inline ulong ulmin(register const ulong a, register const ulong b) {
    return b < a ? b : a;
}

inline llong llmin(register const llong a, register const llong b) {
    return b < a ? b : a;
}

inline ullong ullmin(register const ullong a, register const ullong b) {
    return b < a ? b : a;
}

inline intmax_t imaxmin(
    register const intmax_t a,
    register const intmax_t b
) {
    return b < a ? b : a;
}

inline uintmax_t umaxmin(
    register const uintmax_t a,
    register const uintmax_t b
) {
    return b < a ? b : a;
}

#if UINTMAX_MAX > ULLONG_MAX

#define abs(X) _Generic((X), \
    int: abs, \
    long: labs, \
    llong: llabs, \
    intmax_t: imaxabs, \
    default: abs \
)(X)

#define div(X, Y) _Generic((X) + (Y), \
    int: div, \
    long: ldiv, \
    llong: lldiv, \
    intmax_t: imaxdiv, \
    default: div \
)(X, Y)

#define max(X) _Generic((X) + (Y), \
    int: max, \
    uint: umax, \
    long: lmax, \
    ulong: ulmax, \
    llong: llmax, \
    ullong: ullmax, \
    intmax_t: imaxmax, \
    uintmax_t: umaxmax, \
    default: max \
)(X)

#define min(X) _Generic((X) + (Y), \
    int: min, \
    uint: umin, \
    long: lmin, \
    ulong: ulmin, \
    llong: llmin, \
    ullong: ullmin, \
    intmax_t: imaxmin, \
    uintmax_t: umaxmin, \
    default: min \
)(X)

#else

#define abs(X) _Generic((X), \
    int: abs, \
    long: labs, \
    llong: llabs, \
    default: abs \
)(X)

#define div(X, Y) _Generic((X) + (Y), \
    int: div, \
    long: ldiv, \
    llong: lldiv, \
    default: div \
)(X, Y)

#define max(X) _Generic((X) + (Y), \
    int: max, \
    uint: umax, \
    long: lmax, \
    ulong: ulmax, \
    llong: llmax, \
    ullong: ullmax, \
    default: max \
)(X)

#define min(X) _Generic((X) + (Y), \
    int: min, \
    uint: umin, \
    long: lmin, \
    ulong: ulmin, \
    llong: llmin, \
    ullong: ullmin, \
    default: min \
)(X)

#endif // UINTMAX_MAX > ULLONG_MAX

inline void *mem_offset(
    register const void * const ptr, // restrict ???
    register size_t index,
    register size_t size
) {
    return (void *) ((uchar *) ptr + index * size);
}

inline void *mem_swap(
    void * const restrict s1,
    void * const restrict s2,
    register size_t n
) {
    for (register uchar * restrict ptr1 = s1, * restrict ptr2 = s2;
        n-- > 0; ++ptr1, ++ptr2
    ) {
        const uchar buffer = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = buffer;
    }
    return s1;
}

/* inline void *mem_swap(
    void * const restrict s1,
    void * const restrict s2,
    register size_t n
) {
    uchar buffer[64U]; // uintmax_t ???
    static const size_t size = sizeof buffer;
    for (register uchar * restrict ptr1 = s1, * restrict ptr2 = s2;
        n > 0; ptr1 += size, ptr2 += size
    ) {
        const size_t offset = min(n, size);
        n -= offset;
        memcpy(buffer, ptr1, offset);
        memcpy(ptr1, ptr2, offset);
        memcpy(ptr2, buffer, offset);
    }
    return s1;
} */

#endif

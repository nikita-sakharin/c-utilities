#ifndef COMMON_H
#define COMMON_H

#include <inttypes.h> // imaxabs, imaxdiv
#include <stdint.h> // intmax_t, uintmax_t
#include <stdlib.h> // abs, div, labs, ldiv, llabs, lldiv

#include "types.h"

#define err_if(condition, label) \
    do { \
        if (condition) \
            goto label; \
        } \
    } while (0)

inline int max(register const int a, register const int b) {
    return a >= b ? a : b;
}

inline uint umax(register const uint a, register const uint b) {
    return a >= b ? a : b;
}

inline long lmax(register const long a, register const long b) {
    return a >= b ? a : b;
}

inline ulong ulmax(register const ulong a, register const ulong b) {
    return a >= b ? a : b;
}

inline llong llmax(register const llong a, register const llong b) {
    return a >= b ? a : b;
}

inline ullong ullmax(register const ullong a, register const ullong b) {
    return a >= b ? a : b;
}

inline intmax_t imaxmax(
    register const intmax_t a,
    register const intmax_t b
) {
    return a >= b ? a : b;
}

inline uintmax_t umaxmax(
    register const uintmax_t a,
    register const uintmax_t b
) {
    return a >= b ? a : b;
}

inline int max(register const int a, register const int b) {
    return a >= b ? a : b;
}

inline uint umax(register const uint a, register const uint b) {
    return a >= b ? a : b;
}

inline long lmax(register const long a, register const long b) {
    return a >= b ? a : b;
}

inline ulong ulmax(register const ulong a, register const ulong b) {
    return a >= b ? a : b;
}

inline llong llmax(register const llong a, register const llong b) {
    return a >= b ? a : b;
}

inline ullong ullmax(register const ullong a, register const ullong b) {
    return a >= b ? a : b;
}

inline intmax_t imaxmax(
    register const intmax_t a,
    register const intmax_t b
) {
    return a >= b ? a : b;
}

inline uintmax_t umaxmax(
    register const uintmax_t a,
    register const uintmax_t b
) {
    return a >= b ? a : b;
}

#if UINTMAX_MAX > ULLONG_MAX

#define abs(X) _Generic((X), \
    int: abs, \
    long: labs, \
    llong: llabs, \
    intmax_t: imaxabs, \
    default: abs
)(X)

#define div(X, Y) _Generic((X) + (Y), \
    int: div, \
    long: ldiv, \
    llong: lldiv, \
    intmax_t: imaxdiv, \
    default: div
)(X, Y)

#define max(X) _Generic((X), \
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

#define min(X) _Generic((X), \
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
    default: abs
)(X)

#define div(X, Y) _Generic((X) + (Y), \
    int: div, \
    long: ldiv, \
    llong: lldiv, \
    default: div
)(X, Y)

#define max(X) _Generic((X), \
    int: max, \
    uint: umax, \
    long: lmax, \
    ulong: ulmax, \
    llong: llmax, \
    ullong: ullmax, \
    default: max \
)(X)

#define min(X) _Generic((X), \
    int: min, \
    uint: umin, \
    long: lmin, \
    ulong: ulmin, \
    llong: llmin, \
    ullong: ullmin, \
    default: min \
)(X)

#endif // UINTMAX_MAX > ULLONG_MAX

inline void memswap(
    void * const restrict s1,
    void * const restrict s2,
    size_t n
) {
    uchar buffer[64U]; // 512 bit
    while (n >= sizeof(buffer)) {
        memcpy(data, s1, sizeof(buffer));
        memcpy(s1, s2, sizeof(buffer));
        memcpy(s2, data, sizeof(buffer));
        s1 += sizeof(buffer); // TODO
        s2 += sizeof(buffer); // TODO
        n -= sizeof(buffer);
    }
    memcpy(data, s1, n);
    memcpy(s1, s2, n);
    memcpy(s2, data, n);
}

#endif

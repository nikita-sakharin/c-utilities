#ifndef C_UTILITIES_ARITHMETIC_H
#define C_UTILITIES_ARITHMETIC_H

#include <inttypes.h> // imaxabs, imaxdiv
#include <limits.h> // LLONG_MAX
#include <stdint.h> // INTMAX_MAX, intmax_t, uintmax_t
#include <stdlib.h> // abs, div, labs, ldiv, llabs, lldiv

#include "types.h"

#define ABS(a) ((a) < 0 ? -(a) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define MIN(a, b) ((b) < (a) ? (b) : (a))

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

#if LLONG_MAX < INTMAX_MAX

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

#define max(X, Y) _Generic((X) + (Y), \
    int: max, \
    uint: umax, \
    long: lmax, \
    ulong: ulmax, \
    llong: llmax, \
    ullong: ullmax, \
    intmax_t: imaxmax, \
    uintmax_t: umaxmax, \
    default: max \
)(X, Y)

#define min(X, Y) _Generic((X) + (Y), \
    int: min, \
    uint: umin, \
    long: lmin, \
    ulong: ulmin, \
    llong: llmin, \
    ullong: ullmin, \
    intmax_t: imaxmin, \
    uintmax_t: umaxmin, \
    default: min \
)(X, Y)

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

#define max(X, Y) _Generic((X) + (Y), \
    int: max, \
    uint: umax, \
    long: lmax, \
    ulong: ulmax, \
    llong: llmax, \
    ullong: ullmax, \
    default: max \
)(X, Y)

#define min(X, Y) _Generic((X) + (Y), \
    int: min, \
    uint: umin, \
    long: lmin, \
    ulong: ulmin, \
    llong: llmin, \
    ullong: ullmin, \
    default: min \
)(X, Y)

#endif // LLONG_MAX < INTMAX_MAX

#endif // C_UTILITIES_ARITHMETIC_H

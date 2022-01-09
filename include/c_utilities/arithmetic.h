#ifndef C_UTILITIES_ARITHMETIC_H
#define C_UTILITIES_ARITHMETIC_H

#include <assert.h> // assert
#include <inttypes.h> // imaxabs, imaxdiv
#include <stdint.h> // intmax_t, uintmax_t
#include <stdlib.h> // abs, div, labs, ldiv, llabs, lldiv

#include <c_utilities/type_generic.h> // TYPE_GENERIC_*INTEGER_MACRO_*
#include <c_utilities/types.h> // llong, uint, ullong, ulong

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define CLAMP(x, a, b) ((x) < (a) ? (a) : (b) < (x) ? (b) : (x))
#define DIM(x, y) ((y) < (x) ? (x) - (y) : 0)
#define MAX(x, y) ((x) < (y) ? (y) : (x))
#define MIN(x, y) ((y) < (x) ? (y) : (x))

inline int clamp(
    register const int x,
    register const int a,
    register const int b
) {
    assert(a <= b);
    return CLAMP(x, a, b);
}

inline uint uclamp(
    register const uint x,
    register const uint a,
    register const uint b
) {
    assert(a <= b);
    return CLAMP(x, a, b);
}

inline long lclamp(
    register const long x,
    register const long a,
    register const long b
) {
    assert(a <= b);
    return CLAMP(x, a, b);
}

inline ulong ulclamp(
    register const ulong x,
    register const ulong a,
    register const ulong b
) {
    assert(a <= b);
    return CLAMP(x, a, b);
}

inline llong llclamp(
    register const llong x,
    register const llong a,
    register const llong b
) {
    assert(a <= b);
    return CLAMP(x, a, b);
}

inline ullong ullclamp(
    register const ullong x,
    register const ullong a,
    register const ullong b
) {
    assert(a <= b);
    return CLAMP(x, a, b);
}

inline intmax_t imaxclamp(
    register const intmax_t x,
    register const intmax_t a,
    register const intmax_t b
) {
    assert(a <= b);
    return CLAMP(x, a, b);
}

inline uintmax_t umaxclamp(
    register const uintmax_t x,
    register const uintmax_t a,
    register const uintmax_t b
) {
    assert(a <= b);
    return CLAMP(x, a, b);
}

inline int dim(register const int x, register const int y) {
    return DIM(x, y);
}

inline uint udim(register const uint x, register const uint y) {
    return DIM(x, y);
}

inline long ldim(register const long x, register const long y) {
    return DIM(x, y);
}

inline ulong uldim(register const ulong x, register const ulong y) {
    return DIM(x, y);
}

inline llong lldim(register const llong x, register const llong y) {
    return DIM(x, y);
}

inline ullong ulldim(register const ullong x, register const ullong y) {
    return DIM(x, y);
}

inline intmax_t imaxdim(
    register const intmax_t x,
    register const intmax_t y
) {
    return DIM(x, y);
}

inline uintmax_t umaxdim(
    register const uintmax_t x,
    register const uintmax_t y
) {
    return DIM(x, y);
}

inline int max(register const int x, register const int y) {
    return MAX(x, y);
}

inline uint umax(register const uint x, register const uint y) {
    return MAX(x, y);
}

inline long lmax(register const long x, register const long y) {
    return MAX(x, y);
}

inline ulong ulmax(register const ulong x, register const ulong y) {
    return MAX(x, y);
}

inline llong llmax(register const llong x, register const llong y) {
    return MAX(x, y);
}

inline ullong ullmax(register const ullong x, register const ullong y) {
    return MAX(x, y);
}

inline intmax_t imaxmax(
    register const intmax_t x,
    register const intmax_t y
) {
    return MAX(x, y);
}

inline uintmax_t umaxmax(
    register const uintmax_t x,
    register const uintmax_t y
) {
    return MAX(x, y);
}

inline int min(register const int x, register const int y) {
    return MIN(x, y);
}

inline uint umin(register const uint x, register const uint y) {
    return MIN(x, y);
}

inline long lmin(register const long x, register const long y) {
    return MIN(x, y);
}

inline ulong ulmin(register const ulong x, register const ulong y) {
    return MIN(x, y);
}

inline llong llmin(register const llong x, register const llong y) {
    return MIN(x, y);
}

inline ullong ullmin(register const ullong x, register const ullong y) {
    return MIN(x, y);
}

inline intmax_t imaxmin(
    register const intmax_t x,
    register const intmax_t y
) {
    return MIN(x, y);
}

inline uintmax_t umaxmin(
    register const uintmax_t x,
    register const uintmax_t y
) {
    return MIN(x, y);
}

#define abs(x) TYPE_GENERIC_SIGNED_INTEGER_1(abs, x)
#define div(x, y) TYPE_GENERIC_SIGNED_INTEGER_2(div, x, y)
#define clamp(x, a, b) TYPE_GENERIC_INTEGER_3(clamp, x, a, b)
#define dim(x, y) TYPE_GENERIC_INTEGER_2(dim, x, y)
#define max(x, y) TYPE_GENERIC_INTEGER_2(max, x, y)
#define min(x, y) TYPE_GENERIC_INTEGER_2(min, x, y)

#endif // C_UTILITIES_ARITHMETIC_H

#ifndef C_UTILITIES_ARITHMETIC_H
#define C_UTILITIES_ARITHMETIC_H

#include <assert.h> // assert
#include <inttypes.h> // imaxabs, imaxdiv
#include <stdint.h> // intmax_t, uintmax_t
#include <stdlib.h> // abs, div, labs, ldiv, llabs, lldiv

#include <c_utilities/type_generic.h> // TYPE_GENERIC_*INTEGER_FUNCTION_*
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

inline int dim(
    register const int x,
    register const int y
) {
    return DIM(x, y);
}

inline uint udim(
    register const uint x,
    register const uint y
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

#define abs(x) TYPE_GENERIC_SIGNED_INTEGER_FUNCTION_1(abs, x)
#define div(x, y) TYPE_GENERIC_SIGNED_INTEGER_FUNCTION_2(div, x, y)
#define clamp(x, a, b) TYPE_GENERIC_INTEGER_FUNCTION_3(clamp, x, a, b)
#define dim(x, y) TYPE_GENERIC_INTEGER_FUNCTION_2(dim, x, y)
#define max(x, y) TYPE_GENERIC_INTEGER_FUNCTION_2(max, x, y)
#define min(x, y) TYPE_GENERIC_INTEGER_FUNCTION_2(min, x, y)

#endif // C_UTILITIES_ARITHMETIC_H

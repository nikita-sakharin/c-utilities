#ifndef C_UTILITIES_TYPE_GENERIC_H
#define C_UTILITIES_TYPE_GENERIC_H

#include <limits.h> // LLONG_MAX
#include <stdint.h> // INTMAX_MAX, intmax_t, uintmax_t

#include <c_utilities/types.h> // dbl, flt, ldbl, llong, uint, ullong, ulong

#if LLONG_MAX < INTMAX_MAX

#define TYPE_GENERIC_INTEGER_FUNCTION_1(FUNC, X) _Generic((X), \
    int: FUNC, \
    uint: u##FUNC, \
    long: l##FUNC, \
    ulong: ul##FUNC, \
    llong: ll##FUNC, \
    ullong: ull##FUNC, \
    intmax_t: imax##FUNC, \
    uintmax_t: umax##FUNC, \
    default: FUNC \
)(X)

#define TYPE_GENERIC_INTEGER_FUNCTION_2(FUNC, X, Y) _Generic((X) + (Y), \
    int: FUNC, \
    uint: u##FUNC, \
    long: l##FUNC, \
    ulong: ul##FUNC, \
    llong: ll##FUNC, \
    ullong: ull##FUNC, \
    intmax_t: imax##FUNC, \
    uintmax_t: umax##FUNC, \
    default: FUNC \
)(X, Y)

#define TYPE_GENERIC_INTEGER_FUNCTION_3(FUNC, X, Y, Z) _Generic((X) + (Y) + (Z), \
    int: FUNC, \
    uint: u##FUNC, \
    long: l##FUNC, \
    ulong: ul##FUNC, \
    llong: ll##FUNC, \
    ullong: ull##FUNC, \
    intmax_t: imax##FUNC, \
    uintmax_t: umax##FUNC, \
    default: FUNC \
)(X, Y, Z)

#define TYPE_GENERIC_SIGNED_INTEGER_FUNCTION_1(FUNC, X) _Generic((X), \
    int: FUNC, \
    long: l##FUNC, \
    llong: ll##FUNC, \
    intmax_t: imax##FUNC, \
    default: FUNC \
)(X)

#define TYPE_GENERIC_SIGNED_INTEGER_FUNCTION_2(FUNC, X, Y) _Generic((X) + (Y), \
    int: FUNC, \
    long: l##FUNC, \
    llong: ll##FUNC, \
    intmax_t: imax##FUNC, \
    default: FUNC \
)(X, Y)

#define TYPE_GENERIC_SIGNED_INTEGER_FUNCTION_3(FUNC, X, Y, Z) _Generic((X) + (Y) + (Z), \
    int: FUNC, \
    long: l##FUNC, \
    llong: ll##FUNC, \
    intmax_t: imax##FUNC, \
    default: FUNC \
)(X, Y, Z)

#define TYPE_GENERIC_UNSIGNED_INTEGER_FUNCTION_1(FUNC, X) _Generic((X), \
    uint: u##FUNC, \
    ulong: ul##FUNC, \
    ullong: ull##FUNC, \
    uintmax_t: umax##FUNC, \
    default: FUNC \
)(X)

#define TYPE_GENERIC_UNSIGNED_INTEGER_FUNCTION_2(FUNC, X, Y) _Generic((X) + (Y), \
    uint: u##FUNC, \
    ulong: ul##FUNC, \
    ullong: ull##FUNC, \
    uintmax_t: umax##FUNC, \
    default: FUNC \
)(X, Y)

#define TYPE_GENERIC_UNSIGNED_INTEGER_FUNCTION_3(FUNC, X, Y, Z) _Generic((X) + (Y) + (Z), \
    uint: u##FUNC, \
    ulong: ul##FUNC, \
    ullong: ull##FUNC, \
    uintmax_t: umax##FUNC, \
    default: FUNC \
)(X, Y, Z)

#else

#endif // LLONG_MAX < INTMAX_MAX

#endif // C_UTILITIES_TYPE_GENERIC_H

#ifndef C_UTILITIES_TYPE_GENERIC_H
#define C_UTILITIES_TYPE_GENERIC_H

#include <limits.h> // LLONG_MAX
#include <stdint.h> // INTMAX_MAX, intmax_t, uintmax_t

#include <c_utilities/types.h> // dbl, flt, ldbl, llong, uint, ullong, ulong

#if LLONG_MAX < INTMAX_MAX

#define TYPE_GENERIC_INTEGER_MACRO_1(func, x) _Generic( \
    (x), \
    int: func, \
    uint: u##func, \
    long: l##func, \
    ulong: ul##func, \
    llong: ll##func, \
    ullong: ull##func, \
    intmax_t: imax##func, \
    uintmax_t: umax##func, \
    default: func \
)(x)

#define TYPE_GENERIC_SIGNED_INTEGER_MACRO_1(func, x) _Generic( \
    (x), \
    int: func, \
    long: l##func, \
    llong: ll##func, \
    intmax_t: imax##func, \
    default: func \
)(x)

#define TYPE_GENERIC_UNSIGNED_INTEGER_MACRO_1(func, x) _Generic( \
    (x), \
    uint: u##func, \
    ulong: ul##func, \
    ullong: ull##func, \
    uintmax_t: umax##func, \
    default: u##func \
)(x)

#else

#define TYPE_GENERIC_INTEGER_MACRO_1(func, x) _Generic( \
    (x), \
    int: func, \
    uint: u##func, \
    long: l##func, \
    ulong: ul##func, \
    llong: ll##func, \
    ullong: ull##func, \
    default: func \
)(x)

#define TYPE_GENERIC_SIGNED_INTEGER_MACRO_1(func, x) _Generic( \
    (x), \
    int: func, \
    long: l##func, \
    llong: ll##func, \
    default: func \
)(x)

#define TYPE_GENERIC_UNSIGNED_INTEGER_MACRO_1(func, x) _Generic( \
    (x), \
    uint: u##func, \
    ulong: ul##func, \
    ullong: ull##func, \
    default: u##func \
)(x)

#endif // LLONG_MAX < INTMAX_MAX

#define TYPE_GENERIC_REAL_FLOATING_MACRO_1(func, x) _Generic( \
    (x), \
    flt: func##f, \
    dbl: func, \
    ldbl: func##l, \
    default: func \
)(x)

#endif // C_UTILITIES_TYPE_GENERIC_H

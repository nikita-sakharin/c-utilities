#ifndef C_COMMONS_TYPE_GENERIC_H
#define C_COMMONS_TYPE_GENERIC_H

#include <limits.h> // LLONG_MAX
#include <stdint.h> // INTMAX_MAX, intmax_t, uintmax_t

#include <c_commons/types.h> // dbl, flt, ldbl, llong, uint, ullong, ulong

#if LLONG_MAX < INTMAX_MAX

#define TYPE_GENERIC_INTEGER(func, expr, ...) _Generic((expr), \
    default: func,                                             \
    uint: u##func,                                             \
    long: l##func,                                             \
    ulong: ul##func,                                           \
    llong: ll##func,                                           \
    ullong: ull##func,                                         \
    intmax_t: imax##func,                                      \
    uintmax_t: umax##func                                      \
)(__VA_ARGS__)

#define TYPE_GENERIC_SIGNED_INTEGER(func, expr, ...) _Generic((expr), \
    default: func,                                                    \
    long: l##func,                                                    \
    llong: ll##func,                                                  \
    intmax_t: imax##func                                              \
)(__VA_ARGS__)

#define TYPE_GENERIC_UNSIGNED_INTEGER(func, expr, ...) _Generic((expr), \
    default: u##func,                                                   \
    ulong: ul##func,                                                    \
    ullong: ull##func,                                                  \
    uintmax_t: umax##func                                               \
)(__VA_ARGS__)

#else // LLONG_MAX == INTMAX_MAX

#define TYPE_GENERIC_INTEGER(func, expr, ...) _Generic((expr), \
    default: func,                                             \
    uint: u##func,                                             \
    long: l##func,                                             \
    ulong: ul##func,                                           \
    llong: ll##func,                                           \
    ullong: ull##func                                          \
)(__VA_ARGS__)

#define TYPE_GENERIC_SIGNED_INTEGER(func, expr, ...) _Generic((expr), \
    default: func,                                                    \
    long: l##func,                                                    \
    llong: ll##func                                                   \
)(__VA_ARGS__)

#define TYPE_GENERIC_UNSIGNED_INTEGER(func, expr, ...) _Generic((expr), \
    default: u##func,                                                   \
    ulong: ul##func,                                                    \
    ullong: ull##func                                                   \
)(__VA_ARGS__)

#endif // LLONG_MAX == INTMAX_MAX

#define TYPE_GENERIC_REAL_FLOATING(func, expr, ...) _Generic((expr), \
    flt: func##f,                                                    \
    default: func,                                                   \
    ldbl: func##l                                                    \
)(__VA_ARGS__)

#define TYPE_GENERIC_INTEGER_1(func, x, ...) \
    TYPE_GENERIC_INTEGER( \
        func, (x), x __VA_OPT__(,) __VA_ARGS__ \
    )

#define TYPE_GENERIC_INTEGER_2(func, x, y, ...) \
    TYPE_GENERIC_INTEGER( \
        func, (x) + (y), x, y __VA_OPT__(,) __VA_ARGS__ \
    )

#define TYPE_GENERIC_INTEGER_3(func, x, y, z, ...) \
    TYPE_GENERIC_INTEGER( \
        func, (x) + (y) + (z), x, y, z __VA_OPT__(,) __VA_ARGS__ \
    )

#define TYPE_GENERIC_INTEGER_4(func, x, y, z, w, ...) \
    TYPE_GENERIC_INTEGER( \
        func, (x) + (y) + (z) + (w), x, y, z, w __VA_OPT__(,) __VA_ARGS__ \
    )

#define TYPE_GENERIC_SIGNED_INTEGER_1(func, x, ...) \
    TYPE_GENERIC_SIGNED_INTEGER( \
        func, (x), x __VA_OPT__(,) __VA_ARGS__ \
    )

#define TYPE_GENERIC_SIGNED_INTEGER_2(func, x, y, ...) \
    TYPE_GENERIC_SIGNED_INTEGER( \
        func, (x) + (y), x, y __VA_OPT__(,) __VA_ARGS__ \
    )

#define TYPE_GENERIC_SIGNED_INTEGER_3(func, x, y, z, ...) \
    TYPE_GENERIC_SIGNED_INTEGER( \
        func, (x) + (y) + (z), x, y, z __VA_OPT__(,) __VA_ARGS__ \
    )

#define TYPE_GENERIC_SIGNED_INTEGER_4(func, x, y, z, w, ...) \
    TYPE_GENERIC_SIGNED_INTEGER( \
        func, (x) + (y) + (z) + (w), x, y, z, w __VA_OPT__(,) __VA_ARGS__ \
    )

#define TYPE_GENERIC_UNSIGNED_INTEGER_1(func, x, ...) \
    TYPE_GENERIC_UNSIGNED_INTEGER( \
        func, (x), x __VA_OPT__(,) __VA_ARGS__ \
    )

#define TYPE_GENERIC_UNSIGNED_INTEGER_2(func, x, y, ...) \
    TYPE_GENERIC_UNSIGNED_INTEGER( \
        func, (x) + (y), x, y __VA_OPT__(,) __VA_ARGS__ \
    )

#define TYPE_GENERIC_UNSIGNED_INTEGER_3(func, x, y, z, ...) \
    TYPE_GENERIC_UNSIGNED_INTEGER( \
        func, (x) + (y) + (z), x, y, z __VA_OPT__(,) __VA_ARGS__ \
    )

#define TYPE_GENERIC_UNSIGNED_INTEGER_4(func, x, y, z, w, ...) \
    TYPE_GENERIC_UNSIGNED_INTEGER( \
        func, (x) + (y) + (z) + (w), x, y, z, w __VA_OPT__(,) __VA_ARGS__ \
    )

#define TYPE_GENERIC_REAL_FLOATING_1(func, x, ...) \
    TYPE_GENERIC_REAL_FLOATING( \
        func, (x), x __VA_OPT__(,) __VA_ARGS__ \
    )

#define TYPE_GENERIC_REAL_FLOATING_2(func, x, y, ...) \
    TYPE_GENERIC_REAL_FLOATING( \
        func, (x) + (y), x, y __VA_OPT__(,) __VA_ARGS__ \
    )

#define TYPE_GENERIC_REAL_FLOATING_3(func, x, y, z, ...) \
    TYPE_GENERIC_REAL_FLOATING( \
        func, (x) + (y) + (z), x, y, z __VA_OPT__(,) __VA_ARGS__ \
    )

#define TYPE_GENERIC_REAL_FLOATING_4(func, x, y, z, w, ...) \
    TYPE_GENERIC_REAL_FLOATING( \
        func, (x) + (y) + (z) + (w), x, y, z, w __VA_OPT__(,) __VA_ARGS__ \
    )

#endif // C_COMMONS_TYPE_GENERIC_H

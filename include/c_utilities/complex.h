#ifndef C_UTILITIES_COMPLEX_H
#define C_UTILITIES_COMPLEX_H

#ifndef __STDC_NO_COMPLEX__

#include <complex.h> // complex

typedef float complex fltCmplx;
typedef double complex dblCmplx;
typedef long double complex ldblCmplx;

#define TYPE_GENERIC_COMPLEX(func, expr, ...) _Generic((expr), \
    fltCmplx: func##f, \
    default: func, \
    ldblCmplx: func##l \
)(__VA_ARGS__)

#define TYPE_GENERIC_FLOATING(func, expr, ...) _Generic((expr), \
    flt: func##f, \
    default: func, \
    ldbl: func##l, \
    fltCmplx: c##func##f, \
    dblCmplx: c##func, \
    ldblCmplx: c##func##l \
)(__VA_ARGS__)

#define TYPE_GENERIC_COMPLEX_1(func, x, ...) \
    TYPE_GENERIC_COMPLEX( \
        func, (x), x __VA_OPT__(,) __VA_ARGS__ \
    )

#define TYPE_GENERIC_COMPLEX_2(func, x, y, ...) \
    TYPE_GENERIC_COMPLEX( \
        func, (x) + (y), x, y __VA_OPT__(,) __VA_ARGS__ \
    )

#define TYPE_GENERIC_COMPLEX_3(func, x, y, z, ...) \
    TYPE_GENERIC_COMPLEX( \
        func, (x) + (y) + (z), x, y, z __VA_OPT__(,) __VA_ARGS__ \
    )

#define TYPE_GENERIC_COMPLEX_4(func, x, y, z, w, ...) \
    TYPE_GENERIC_COMPLEX( \
        func, (x) + (y) + (z) + (w), x, y, z, w __VA_OPT__(,) __VA_ARGS__ \
    )

#define TYPE_GENERIC_FLOATING_1(func, x, ...) \
    TYPE_GENERIC_FLOATING( \
        func, (x), x __VA_OPT__(,) __VA_ARGS__ \
    )

#define TYPE_GENERIC_FLOATING_2(func, x, y, ...) \
    TYPE_GENERIC_FLOATING( \
        func, (x) + (y), x, y __VA_OPT__(,) __VA_ARGS__ \
    )

#define TYPE_GENERIC_FLOATING_3(func, x, y, z, ...) \
    TYPE_GENERIC_FLOATING( \
        func, (x) + (y) + (z), x, y, z __VA_OPT__(,) __VA_ARGS__ \
    )

#define TYPE_GENERIC_FLOATING_4(func, x, y, z, w, ...) \
    TYPE_GENERIC_FLOATING( \
        func, (x) + (y) + (z) + (w), x, y, z, w __VA_OPT__(,) __VA_ARGS__ \
    )

#endif // __STDC_NO_COMPLEX__

#endif // C_UTILITIES_COMPLEX_H

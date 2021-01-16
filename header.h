#ifndef HEADER_H
#define HEADER_H

#include <inttypes.h> // imaxabs, imaxdiv
#include <stddef.h> // ptrdiff_t, size_t
#include <stdint.h> // intmax_t, uintmax_t
#include <stdlib.h> // abs, div, labs, ldiv, llabs, lldiv

typedef signed char schar;
typedef unsigned char uchar;
typedef short shrt;
typedef unsigned short ushrt;
typedef unsigned uint;
typedef unsigned long ulong;
typedef long long llong;
typedef unsigned long long ullong;
typedef float flt;
typedef double dbl;
typedef long double ldbl;

#define err_if(cnd_value, label) \
    do { \
        if (cnd_value) { \
            goto label; \
        } \
    } while (0);

#define abs(X) _Generic((X), \
    int: abs, \
    long: labs, \
    llong: llabs, \
    default: imaxabs \
)(X)

#define div(X, Y) _Generic((X) + (Y), \
    int: div, \
    long: ldiv, \
    llong: lldiv, \
    default: imaxdiv \
)(X, Y)

#define max(X) _Generic((X), \
    int: max, \
    uint: umax, \
    long: lmax, \
    ulong: ulmax, \
    llong: llmax, \
    ullong: ullmax, \
    intmax_t: imaxmax, \
    uintmax_t: uimaxmax, \ // TODO
    default: uimaxmax \
)(X)

#define min(X) _Generic((X), \
    int: min, \
    long: lmin, \
    llong: llmin, \
    default: imaxmin \
)(X)

int max(int, int);
uint umax(uint, uint); // maxu
long lmax(long, long); // maxl
ulong ulmax(ulong, ulong); // maxul
llong llmax(llong, llong); // maxll
ullong ullmax(ullong, ullong); // maxull
intmax_t imaxmax(intmax_t, intmax_t); // jmax, maxj
uintmax_t uimaxmax(uintmax_t, uintmax_t); // ujmax, maxuj
// size_t uzmax(size_t, size_t); // maxuz
// ptrdiff_t tmax(ptrdiff_t, ptrdiff_t); // maxt

int min(int, int);
uint umin(uint, uint); // minu
long lmin(long, long); // minl
ulong ulmin(ulong, ulong); // minul
llong llmin(llong, llong); // minll
ullong ullmin(ullong, ullong); // minull
intmax_t imaxmin(intmax_t, intmax_t); // jmin, minj
uintmax_t uimaxmin(uintmax_t, uintmax_t); // ujmin, minuj
// size_t uzmin(size_t, size_t); // minuz
// ptrdiff_t tmin(ptrdiff_t, ptrdiff_t); // mint

#endif

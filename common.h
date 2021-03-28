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

int max(int, int);
uint umax(uint, uint); // maxu
long lmax(long, long); // maxl
ulong ulmax(ulong, ulong); // maxul
llong llmax(llong, llong); // maxll
ullong ullmax(ullong, ullong); // maxull
intmax_t imaxmax(intmax_t, intmax_t); // maximax
uintmax_t umaxmax(uintmax_t, uintmax_t); // maxumax

int min(int, int);
uint umin(uint, uint); // minu
long lmin(long, long); // minl
ulong ulmin(ulong, ulong); // minul
llong llmin(llong, llong); // minll
ullong ullmin(ullong, ullong); // minull
intmax_t imaxmin(intmax_t, intmax_t); // minimax
uintmax_t umaxmin(uintmax_t, uintmax_t); // minumax

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

inline void memswap(
    void * const restrict s1,
    void * const restrict s2,
    size_t n
) {
    uchar buffer[64]; // 512 bit
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

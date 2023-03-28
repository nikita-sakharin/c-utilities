#ifndef C_UTILITIES_ARITHMETIC_H
#define C_UTILITIES_ARITHMETIC_H

#include <assert.h> // assert
#include <inttypes.h> // imaxabs, imaxdiv
#include <stdbool.h> // bool
#include <stdint.h> // intmax_t, uintmax_t
#include <stdlib.h> // abs, div, labs, ldiv, llabs, lldiv

#include <c_utilities/type_generic.h> // TYPE_GENERIC_*INTEGER_*
#include <c_utilities/types.h> // llong, uint, ullong, ulong

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define ABS_DIFF(x, y) ((x) < (y) ? (y) - (x) : (x) - (y))
#define CEIL_DIV(x, y) ((x) / (y) + (((x) ^ (y)) >= 0 && (x) % (y) != 0))
#define CEIL_MOD(x, y) (((x) ^ (y)) >= 0 && (x) % (y) != 0 ? (x) % (y) - (y) : (x) % (y))
#define CLAMP(x, a, b) ((x) < (a) ? (a) : (b) < (x) ? (b) : (x))
#define DIM(x, y) ((y) < (x) ? (x) - (y) : 0)
#define EUCLID_DIV(x, y) ((x) / (y) + ((x) % (y) < 0 ? (y) > 0 ? -1 : 1 : 0))
#define EUCLID_MOD(x, y) ((x) % (y) < 0 ? (y) < 0 ? (x) % (y) - (y) : (x) % (y) + (y) : (x) % (y))
#define FLOOR_DIV(x, y) ((x) / (y) - (((x) ^ (y)) < 0 && (x) % (y) != 0))
#define FLOOR_MOD(x, y) (((x) ^ (y)) < 0 && (x) % (y) != 0 ? (x) % (y) + (y) : (x) % (y))
#define IN_RANGE(x, a, b) ((x) >= (a) && (b) >= (x))
#define MAX(x, y) ((x) < (y) ? (y) : (x))
#define MIDPOINT(x, y) ((x) / 2 + (y) / 2 + ((x) % 2 + (y) % 2) / 2)
#define MIDPOINT_CEIL(x, y) (((x) >> 1) + ((y) >> 1) + (((x) | (y)) & 1))
#define MIDPOINT_FLOOR(x, y) (((x) >> 1) + ((y) >> 1) + ((x) & (y) & 1))
// MIN(x, y) + ABS(x / 2 - y / 2), MAX(x, y) - ABS(x / 2 - y / 2)
// (x & y) + ((x ^ y) >> 1), (x | y) - ((x ^ y) >> 1)
#define MIN(x, y) ((y) < (x) ? (y) : (x))
#define SIGN(x) ((x) < 0 ? -1 : 0 < (x))

inline uint absDiff(register const int x, register const int y) {
    return x < y ? (uint) y - (uint) x : (uint) x - (uint) y;
}

inline uint uabsDiff(register const uint x, register const uint y) {
    return ABS_DIFF(x, y);
}

inline ulong labsDiff(register const long x, register const long y) {
    return x < y ? (ulong) y - (ulong) x : (ulong) x - (ulong) y;
}

inline ulong ulabsDiff(register const ulong x, register const ulong y) {
    return ABS_DIFF(x, y);
}

inline ullong llabsDiff(register const llong x, register const llong y) {
    return x < y ? (ullong) y - (ullong) x : (ullong) x - (ullong) y;
}

inline ullong ullabsDiff(register const ullong x, register const ullong y) {
    return ABS_DIFF(x, y);
}

inline uintmax_t imaxabsDiff(
    register const intmax_t x,
    register const intmax_t y
) {
    return x < y ? (uintmax_t) y - (uintmax_t) x : (uintmax_t) x - (uintmax_t) y;
}

inline uintmax_t umaxabsDiff(
    register const uintmax_t x,
    register const uintmax_t y
) {
    return ABS_DIFF(x, y);
}

inline int ceilDiv(register const int x, register const int y) {
    assert(y != 0);
    return CEIL_DIV(x, y);
}

inline uint uceilDiv(register const uint x, register const uint y) {
    assert(y != 0);
    return x / y + (x % y != 0U);
}

inline long lceilDiv(register const long x, register const long y) {
    assert(y != 0);
    return CEIL_DIV(x, y);
}

inline ulong ulceilDiv(register const ulong x, register const ulong y) {
    assert(y != 0);
    return x / y + (x % y != 0U);
}

inline llong llceilDiv(register const llong x, register const llong y) {
    assert(y != 0);
    return CEIL_DIV(x, y);
}

inline ullong ullceilDiv(register const ullong x, register const ullong y) {
    assert(y != 0);
    return x / y + (x % y != 0U);
}

inline intmax_t imaxceilDiv(
    register const intmax_t x,
    register const intmax_t y
) {
    assert(y != 0);
    return CEIL_DIV(x, y);
}

inline uintmax_t umaxceilDiv(
    register const uintmax_t x,
    register const uintmax_t y
) {
    assert(y != 0);
    return x / y + (x % y != 0U);
}

inline int ceilMod(register const int x, register const int y) {
    assert(y != 0);
    return CEIL_MOD(x, y);
}

inline uint uceilMod(register const uint x, register const uint y) {
    assert(y != 0);
    return CEIL_MOD(x, y);
}

inline long lceilMod(register const long x, register const long y) {
    assert(y != 0);
    return CEIL_MOD(x, y);
}

inline ulong ulceilMod(register const ulong x, register const ulong y) {
    assert(y != 0);
    return CEIL_MOD(x, y);
}

inline llong llceilMod(register const llong x, register const llong y) {
    assert(y != 0);
    return CEIL_MOD(x, y);
}

inline ullong ullceilMod(register const ullong x, register const ullong y) {
    assert(y != 0);
    return CEIL_MOD(x, y);
}

inline intmax_t imaxceilMod(
    register const intmax_t x,
    register const intmax_t y
) {
    assert(y != 0);
    return CEIL_MOD(x, y);
}

inline uintmax_t umaxceilMod(
    register const uintmax_t x,
    register const uintmax_t y
) {
    assert(y != 0);
    return CEIL_MOD(x, y);
}

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

inline uint dim(register const int x, register const int y) {
    return (uint) DIM(x, y);
}

inline uint udim(register const uint x, register const uint y) {
    return DIM(x, y);
}

inline ulong ldim(register const long x, register const long y) {
    return (ulong) DIM(x, y);
}

inline ulong uldim(register const ulong x, register const ulong y) {
    return DIM(x, y);
}

inline ullong lldim(register const llong x, register const llong y) {
    return (ullong) DIM(x, y);
}

inline ullong ulldim(register const ullong x, register const ullong y) {
    return DIM(x, y);
}

inline uintmax_t imaxdim(
    register const intmax_t x,
    register const intmax_t y
) {
    return (uintmax_t) DIM(x, y);
}

inline uintmax_t umaxdim(
    register const uintmax_t x,
    register const uintmax_t y
) {
    return DIM(x, y);
}

inline int euclidDiv(register const int x, register const int y) {
    assert(y != 0);
    return EUCLID_DIV(x, y);
}

inline uint ueuclidDiv(register const uint x, register const uint y) {
    assert(y != 0);
    return x / y;
}

inline long leuclidDiv(register const long x, register const long y) {
    assert(y != 0);
    return EUCLID_DIV(x, y);
}

inline ulong uleuclidDiv(register const ulong x, register const ulong y) {
    assert(y != 0);
    return x / y;
}

inline llong lleuclidDiv(register const llong x, register const llong y) {
    assert(y != 0);
    return EUCLID_DIV(x, y);
}

inline ullong ulleuclidDiv(register const ullong x, register const ullong y) {
    assert(y != 0);
    return x / y;
}

inline intmax_t imaxeuclidDiv(
    register const intmax_t x,
    register const intmax_t y
) {
    assert(y != 0);
    return EUCLID_DIV(x, y);
}

inline uintmax_t umaxeuclidDiv(
    register const uintmax_t x,
    register const uintmax_t y
) {
    assert(y != 0);
    return x / y;
}

inline int euclidMod(register const int x, register const int y) {
    assert(y != 0);
    return EUCLID_MOD(x, y);
}

inline uint ueuclidMod(register const uint x, register const uint y) {
    assert(y != 0);
    return x % y;
}

inline long leuclidMod(register const long x, register const long y) {
    assert(y != 0);
    return EUCLID_MOD(x, y);
}

inline ulong uleuclidMod(register const ulong x, register const ulong y) {
    assert(y != 0);
    return x % y;
}

inline llong lleuclidMod(register const llong x, register const llong y) {
    assert(y != 0);
    return EUCLID_MOD(x, y);
}

inline ullong ulleuclidMod(register const ullong x, register const ullong y) {
    assert(y != 0);
    return x % y;
}

inline intmax_t imaxeuclidMod(
    register const intmax_t x,
    register const intmax_t y
) {
    assert(y != 0);
    return EUCLID_MOD(x, y);
}

inline uintmax_t umaxeuclidMod(
    register const uintmax_t x,
    register const uintmax_t y
) {
    assert(y != 0);
    return x % y;
}

inline int floorDiv(register const int x, register const int y) {
    assert(y != 0);
    return FLOOR_DIV(x, y);
}

inline uint ufloorDiv(register const uint x, register const uint y) {
    assert(y != 0);
    return x / y;
}

inline long lfloorDiv(register const long x, register const long y) {
    assert(y != 0);
    return FLOOR_DIV(x, y);
}

inline ulong ulfloorDiv(register const ulong x, register const ulong y) {
    assert(y != 0);
    return x / y;
}

inline llong llfloorDiv(register const llong x, register const llong y) {
    assert(y != 0);
    return FLOOR_DIV(x, y);
}

inline ullong ullfloorDiv(register const ullong x, register const ullong y) {
    assert(y != 0);
    return x / y;
}

inline intmax_t imaxfloorDiv(
    register const intmax_t x,
    register const intmax_t y
) {
    assert(y != 0);
    return FLOOR_DIV(x, y);
}

inline uintmax_t umaxfloorDiv(
    register const uintmax_t x,
    register const uintmax_t y
) {
    assert(y != 0);
    return x / y;
}

inline int floorMod(register const int x, register const int y) {
    assert(y != 0);
    return FLOOR_MOD(x, y);
}

inline uint ufloorMod(register const uint x, register const uint y) {
    assert(y != 0);
    return x % y;
}

inline long lfloorMod(register const long x, register const long y) {
    assert(y != 0);
    return FLOOR_MOD(x, y);
}

inline ulong ulfloorMod(register const ulong x, register const ulong y) {
    assert(y != 0);
    return x % y;
}

inline llong llfloorMod(register const llong x, register const llong y) {
    assert(y != 0);
    return FLOOR_MOD(x, y);
}

inline ullong ullfloorMod(register const ullong x, register const ullong y) {
    assert(y != 0);
    return x % y;
}

inline intmax_t imaxfloorMod(
    register const intmax_t x,
    register const intmax_t y
) {
    assert(y != 0);
    return FLOOR_MOD(x, y);
}

inline uintmax_t umaxfloorMod(
    register const uintmax_t x,
    register const uintmax_t y
) {
    assert(y != 0);
    return x % y;
}

inline bool inRange(
    register const int x,
    register const int a,
    register const int b
) {
    assert(a <= b);
    return IN_RANGE(x, a, b);
}

inline bool uinRange(
    register const uint x,
    register const uint a,
    register const uint b
) {
    assert(a <= b);
    return IN_RANGE(x, a, b);
}

inline bool linRange(
    register const long x,
    register const long a,
    register const long b
) {
    assert(a <= b);
    return IN_RANGE(x, a, b);
}

inline bool ulinRange(
    register const ulong x,
    register const ulong a,
    register const ulong b
) {
    assert(a <= b);
    return IN_RANGE(x, a, b);
}

inline bool llinRange(
    register const llong x,
    register const llong a,
    register const llong b
) {
    assert(a <= b);
    return IN_RANGE(x, a, b);
}

inline bool ullinRange(
    register const ullong x,
    register const ullong a,
    register const ullong b
) {
    assert(a <= b);
    return IN_RANGE(x, a, b);
}

inline bool imaxinRange(
    register const intmax_t x,
    register const intmax_t a,
    register const intmax_t b
) {
    assert(a <= b);
    return IN_RANGE(x, a, b);
}

inline bool umaxinRange(
    register const uintmax_t x,
    register const uintmax_t a,
    register const uintmax_t b
) {
    assert(a <= b);
    return IN_RANGE(x, a, b);
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

inline int sign(register const int x) {
    return SIGN(x);
}

inline int lsign(register const long x) {
    return SIGN(x);
}

inline int llsign(register const llong x) {
    return SIGN(x);
}

inline int imaxsign(register const intmax_t x) {
    return SIGN(x);
}

#define abs(x) TYPE_GENERIC_SIGNED_INTEGER_1(abs, x)
#define absDiff(x, y) TYPE_GENERIC_INTEGER_2(absDiff, x, y)
#define ceilDiv(x, y) TYPE_GENERIC_INTEGER_2(ceilDiv, x, y)
#define ceilMod(x, y) TYPE_GENERIC_INTEGER_2(ceilMod, x, y)
#define clamp(x, a, b) TYPE_GENERIC_INTEGER_3(clamp, x, a, b)
#define dim(x, y) TYPE_GENERIC_INTEGER_2(dim, x, y)
#define div(x, y) TYPE_GENERIC_SIGNED_INTEGER_2(div, x, y)
#define euclidDiv(x, y) TYPE_GENERIC_INTEGER_2(euclidDiv, x, y)
#define euclidMod(x, y) TYPE_GENERIC_INTEGER_2(euclidMod, x, y)
#define floorDiv(x, y) TYPE_GENERIC_INTEGER_2(floorDiv, x, y)
#define floorMod(x, y) TYPE_GENERIC_INTEGER_2(floorMod, x, y)
#define inRange(x, a, b) TYPE_GENERIC_INTEGER_3(inRange, x, a, b)
#define max(x, y) TYPE_GENERIC_INTEGER_2(max, x, y)
#define min(x, y) TYPE_GENERIC_INTEGER_2(min, x, y)
#define sign(x) TYPE_GENERIC_SIGNED_INTEGER_1(sign, x)

#endif // C_UTILITIES_ARITHMETIC_H

/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef C_COMMONS_ARITHMETIC_H
#define C_COMMONS_ARITHMETIC_H

#include <assert.h> // assert
#include <inttypes.h> // imaxabs, imaxdiv
#include <stdbool.h> // bool
#include <stdint.h> // intmax_t, uintmax_t
#include <stdlib.h> // abs, div, labs, ldiv, llabs, lldiv

#include <c_commons/type_generic.h> // TYPE_GENERIC_*INTEGER_*
#include <c_commons/types.h> // llong, uint, ullong, ulong

#define CEIL_DIV(x, y) ((x) / (y) + (((x) ^ (y)) >= 0 && (x) % (y) != 0))
#define CEIL_MOD(x, y) (((x) ^ (y)) >= 0 && (x) % (y) != 0 ? (x) % (y) - (y) : (x) % (y))
#define CLAMP(x, a, b) ((x) < (a) ? (a) : (b) < (x) ? (b) : (x))
#define COMPARE(x, y) ((x) < (y) ? -1 : (y) < (x))
#define DIM(x, y) ((y) < (x) ? (x) - (y) : 0)
#define EUCLID_DIV(x, y) ((x) / (y) + ((x) % (y) < 0 ? 0 < (y) ? -1 : 1 : 0))
#define EUCLID_MOD(x, y) ((x) % (y) < 0 ? (y) < 0 ? (x) % (y) - (y) : (x) % (y) + (y) : (x) % (y))
#define FLOOR_DIV(x, y) ((x) / (y) - (!IS_SAME_SIGN(x, y) && (x) % (y) != 0))
#define FLOOR_MOD(x, y) (!IS_SAME_SIGN(x, y) && (x) % (y) != 0 ? (x) % (y) + (y) : (x) % (y))
#define IS_EVEN(x) (((x) & INTMAX_C(1)) == INTMAX_C(0))
#define IS_ODD(x) (((x) & INTMAX_C(1)) == INTMAX_C(1))
#define IS_SAME_SIGN(x, y) (((x) ^ (y)) >= 0)
#define MIDPOINT(x, y) ((x) + (((y) >> 1) - ((x) >> 1)) + ((((y) & 1) - ((x) & 1) + ((y) < (x))) >> 1))
// #define MIDPOINT(x, y) ((x) + ((y) / 2 - (x) / 2) + (((y) % 2 - (x) % 2 + ((y) < (x))) >> 1))
#define MIDPOINT_CEIL(x, y) (((x) | (y)) - (((x) ^ (y)) >> 1))
// #define MIDPOINT_CEIL(x, y) (((x) >> 1) + ((y) >> 1) + (((x) | (y)) & 1))
// #define MIDPOINT_CEIL(x, y) (MAX(x, y) - ABS(x / 2 - y / 2))
#define MIDPOINT_FLOOR(x, y) (((x) & (y)) + (((x) ^ (y)) >> 1))
// #define MIDPOINT_FLOOR(x, y) (((x) >> 1) + ((y) >> 1) + ((x) & (y) & 1))
// #define MIDPOINT_FLOOR(x, y) (MIN(x, y) + ABS(x / 2 - y / 2))
#define MIDPOINT_TRUNC(x, y) ((x) / 2 + (y) / 2 + ((x) % 2 + (y) % 2) / 2)
#define SIGN(x) ((x) < 0 ? -1 : 0 < (x))
#define SIGNUM(x) ((x) < 0 ? -1 : 1)

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

inline int compare(
    register const int x,
    register const int y
) {
    return COMPARE(x, y);
}

inline int ucompare(
    register const uint x,
    register const uint y
) {
    return COMPARE(x, y);
}

inline int lcompare(
    register const long x,
    register const long y
) {
    return COMPARE(x, y);
}

inline int ulcompare(
    register const ulong x,
    register const ulong y
) {
    return COMPARE(x, y);
}

inline int llcompare(
    register const llong x,
    register const llong y
) {
    return COMPARE(x, y);
}

inline int ullcompare(
    register const ullong x,
    register const ullong y
) {
    return COMPARE(x, y);
}

inline int imaxcompare(
    register const intmax_t x,
    register const intmax_t y
) {
    return COMPARE(x, y);
}

inline int umaxcompare(
    register const uintmax_t x,
    register const uintmax_t y
) {
    return COMPARE(x, y);
}

inline uint dim(register const int x, register const int y) {
    return y < x ? (uint) x - (uint) y : 0U;
}

inline uint udim(register const uint x, register const uint y) {
    return DIM(x, y);
}

inline ulong ldim(register const long x, register const long y) {
    return y < x ? (ulong) x - (ulong) y : 0U;
}

inline ulong uldim(register const ulong x, register const ulong y) {
    return DIM(x, y);
}

inline ullong lldim(register const llong x, register const llong y) {
    return y < x ? (ullong) x - (ullong) y : 0U;
}

inline ullong ulldim(register const ullong x, register const ullong y) {
    return DIM(x, y);
}

inline uintmax_t imaxdim(
    register const intmax_t x,
    register const intmax_t y
) {
    return y < x ? (uintmax_t) x - (uintmax_t) y : 0U;
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

inline bool inClosedRange(
    register const int x,
    register const int a,
    register const int b
) {
    assert(a <= b);
    return IN_CLOSED_RANGE(x, a, b);
}

inline bool uinClosedRange(
    register const uint x,
    register const uint a,
    register const uint b
) {
    assert(a <= b);
    return IN_CLOSED_RANGE(x, a, b);
}

inline bool linClosedRange(
    register const long x,
    register const long a,
    register const long b
) {
    assert(a <= b);
    return IN_CLOSED_RANGE(x, a, b);
}

inline bool ulinClosedRange(
    register const ulong x,
    register const ulong a,
    register const ulong b
) {
    assert(a <= b);
    return IN_CLOSED_RANGE(x, a, b);
}

inline bool llinClosedRange(
    register const llong x,
    register const llong a,
    register const llong b
) {
    assert(a <= b);
    return IN_CLOSED_RANGE(x, a, b);
}

inline bool ullinClosedRange(
    register const ullong x,
    register const ullong a,
    register const ullong b
) {
    assert(a <= b);
    return IN_CLOSED_RANGE(x, a, b);
}

inline bool imaxinClosedRange(
    register const intmax_t x,
    register const intmax_t a,
    register const intmax_t b
) {
    assert(a <= b);
    return IN_CLOSED_RANGE(x, a, b);
}

inline bool umaxinClosedRange(
    register const uintmax_t x,
    register const uintmax_t a,
    register const uintmax_t b
) {
    assert(a <= b);
    return IN_CLOSED_RANGE(x, a, b);
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

inline bool isEven(register const int x) {
    return IS_EVEN(x);
}

inline bool uisEven(register const uint x) {
    return IS_EVEN(x);
}

inline bool lisEven(register const long x) {
    return IS_EVEN(x);
}

inline bool ulisEven(register const ulong x) {
    return IS_EVEN(x);
}

inline bool llisEven(register const llong x) {
    return IS_EVEN(x);
}

inline bool ullisEven(register const ullong x) {
    return IS_EVEN(x);
}

inline bool imaxisEven(register const intmax_t x) {
    return IS_EVEN(x);
}

inline bool umaxisEven(register const uintmax_t x) {
    return IS_EVEN(x);
}

inline bool isOdd(register const int x) {
    return IS_ODD(x);
}

inline bool uisOdd(register const uint x) {
    return IS_ODD(x);
}

inline bool lisOdd(register const long x) {
    return IS_ODD(x);
}

inline bool ulisOdd(register const ulong x) {
    return IS_ODD(x);
}

inline bool llisOdd(register const llong x) {
    return IS_ODD(x);
}

inline bool ullisOdd(register const ullong x) {
    return IS_ODD(x);
}

inline bool imaxisOdd(register const intmax_t x) {
    return IS_ODD(x);
}

inline bool umaxisOdd(register const uintmax_t x) {
    return IS_ODD(x);
}

inline bool isSameSign(register const int x, register const int y) {
    return IS_SAME_SIGN(x, y);
}

inline bool lisSameSign(register const long x, register const long y) {
    return IS_SAME_SIGN(x, y);
}

inline bool llisSameSign(register const llong x, register const llong y) {
    return IS_SAME_SIGN(x, y);
}

inline bool imaxisSameSign(
    register const intmax_t x,
    register const intmax_t y
) {
    return IS_SAME_SIGN(x, y);
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

inline int negativeAbs(register const int x) {
    return NEGATIVE_ABS(x);
}

inline long lnegativeAbs(register const long x) {
    return NEGATIVE_ABS(x);
}

inline llong llnegativeAbs(register const llong x) {
    return NEGATIVE_ABS(x);
}

inline intmax_t imaxnegativeAbs(register const intmax_t x) {
    return NEGATIVE_ABS(x);
}

inline int icopysign(register const int x, register const int y) {
    return y < 0 ? negativeAbs(x) : abs(x);
}

inline long licopysign(register const long x, register const long y) {
    return y < 0L ? negativeAbs(x) : abs(x);
}

inline llong llicopysign(register const llong x, register const llong y) {
    return y < 0LL ? negativeAbs(x) : abs(x);
}

inline intmax_t imaxicopysign(
    register const intmax_t x,
    register const intmax_t y
) {
    return y < INTMAX_C(0) ? negativeAbs(x) : abs(x);
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

inline int signum(register const int x) {
    return SIGNUM(x);
}

inline int lsignum(register const long x) {
    return SIGNUM(x);
}

inline int llsignum(register const llong x) {
    return SIGNUM(x);
}

inline int imaxsignum(register const intmax_t x) {
    return SIGNUM(x);
}

inline uint unsignedAbs(register const int x) {
    return x < 0 ? -(uint) x : (uint) x;
}

inline ulong lunsignedAbs(register const long x) {
    return x < 0L ? -(ulong) x : (ulong) x;
}

inline ullong llunsignedAbs(register const llong x) {
    return x < 0LL ? -(ullong) x : (ullong) x;
}

inline uintmax_t imaxunsignedAbs(register const intmax_t x) {
    return x < INTMAX_C(0) ? -(uintmax_t) x : (uintmax_t) x;
}

#define abs(x) TYPE_GENERIC_SIGNED_INTEGER_1(abs, x)
#define absDiff(x, y) TYPE_GENERIC_INTEGER_2(absDiff, x, y)
#define ceilDiv(x, y) TYPE_GENERIC_INTEGER_2(ceilDiv, x, y)
#define ceilMod(x, y) TYPE_GENERIC_INTEGER_2(ceilMod, x, y)
#define clamp(x, a, b) TYPE_GENERIC_INTEGER_3(clamp, x, a, b)
#define compare(x, y) TYPE_GENERIC_INTEGER_2(compare, x, y)
#define dim(x, y) TYPE_GENERIC_INTEGER_2(dim, x, y)
#define div(x, y) TYPE_GENERIC_SIGNED_INTEGER_2(div, x, y)
#define euclidDiv(x, y) TYPE_GENERIC_INTEGER_2(euclidDiv, x, y)
#define euclidMod(x, y) TYPE_GENERIC_INTEGER_2(euclidMod, x, y)
#define floorDiv(x, y) TYPE_GENERIC_INTEGER_2(floorDiv, x, y)
#define floorMod(x, y) TYPE_GENERIC_INTEGER_2(floorMod, x, y)
#define icopysign(x, y) TYPE_GENERIC_SIGNED_INTEGER_2(icopysign, x, y)
#define inClosedRange(x, a, b) TYPE_GENERIC_INTEGER_3(inClosedRange, x, a, b)
#define inRange(x, a, b) TYPE_GENERIC_INTEGER_3(inRange, x, a, b)
#define isEven(x) TYPE_GENERIC_INTEGER_1(isEven, x)
#define isOdd(x) TYPE_GENERIC_INTEGER_1(isOdd, x)
#define isSameSign(x, y) TYPE_GENERIC_SIGNED_INTEGER_2(isSameSign, x, y)
#define max(x, y) TYPE_GENERIC_INTEGER_2(max, x, y)
#define min(x, y) TYPE_GENERIC_INTEGER_2(min, x, y)
#define negativeAbs(x) TYPE_GENERIC_SIGNED_INTEGER_1(negativeAbs, x)
#define sign(x) TYPE_GENERIC_SIGNED_INTEGER_1(sign, x)
#define unsignedAbs(x) TYPE_GENERIC_SIGNED_INTEGER_1(unsignedAbs, x)

#endif // C_COMMONS_ARITHMETIC_H

#ifndef C_UTILITIES_BIT_H
#define C_UTILITIES_BIT_H

#include <stdbool.h> // bool
#include <stdint.h> // intmax_t, uintmax_t

#include <c_utilities/type_generic.h> // TYPE_GENERIC_*INTEGER_1
#include <c_utilities/types.h> // llong, uint, ullong, ulong

// #define ALL(x) ((x) ^ ~(x))
// #define ALL(x) ((x) | ~(x))
// #define ALL(x) (~NONE(x))
#define IS_EVEN(x) (((x) & 1) == 0)
#define IS_ODD(x) (((x) & 1) == 1)
#define IS_POWER_OF_TWO(x) ((x) > 0 && ((x) & ((x) - 1)) == 0)
#define IS_SAME_SIGN(x, y) (((x) ^ (y)) >= 0)
// HAS_SAME_SIGN, HAS_SAME_SIGNUM, IS_SAME_SIGNUM, SAME_SIGN, SAME_SIGNUM
// #define IS_SIGNED(x) (ALL(x) < 0)
// #define IS_SIGNED(x) (!IS_UNSIGNED(x))
// #define IS_UNSIGNED(x) (ALL(x) >= 0)
// #define IS_UNSIGNED(x) (!IS_SIGNED(x))
// #define NONE(x) ((x) - (x))
// #define NONE(x) ((x) & 0)
// #define NONE(x) ((x) ^ (x))
// #define NONE(x) (~ALL(x))
// #define ROTATE_LEFT(x, shift, width)
// #define ROTATE_RIGHT(x, shift, width)

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

inline bool uisPowerOfTwo(register const uint x) {
    return IS_POWER_OF_TWO(x);
}

inline bool ulisPowerOfTwo(register const ulong x) {
    return IS_POWER_OF_TWO(x);
}

inline bool ullisPowerOfTwo(register const ullong x) {
    return IS_POWER_OF_TWO(x);
}

inline bool umaxisPowerOfTwo(register const uintmax_t x) {
    return IS_POWER_OF_TWO(x);
}

#define isEven(x) TYPE_GENERIC_INTEGER_1(isEven, x)
#define isOdd(x) TYPE_GENERIC_INTEGER_1(isOdd, x)
#define isPowerOfTwo(x) TYPE_GENERIC_UNSIGNED_INTEGER_1(isPowerOfTwo, x)

#endif // C_UTILITIES_BIT_H

#ifndef C_UTILITIES_BIT_H
#define C_UTILITIES_BIT_H

#include <stdbool.h> // bool
#include <stdint.h> // intmax_t, uintmax_t

#include <c_utilities/type_generic.h> // TYPE_GENERIC_*INTEGER_1
#include <c_utilities/types.h> // llong, uint, ullong, ulong

// #define ALL(x) ((x) ^ ~(x))
// #define ALL(x) ((x) | ~(x))
// #define ALL(x) (~NONE(x))
#define IS_POWER_OF_TWO(x) ((x) > 0 && ((x) & ((x) - 1)) == 0)
#define IS_SAME_SIGN(x, y) (((x) ^ (y)) >= 0)
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

#define isPowerOfTwo(x) TYPE_GENERIC_UNSIGNED_INTEGER_1(isPowerOfTwo, x)
#define isSameSign(x, y) TYPE_GENERIC_SIGNED_INTEGER_2(isSameSign, x, y)

#endif // C_UTILITIES_BIT_H

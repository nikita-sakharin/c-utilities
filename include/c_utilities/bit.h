#ifndef C_UTILITIES_BIT_H
#define C_UTILITIES_BIT_H

#include <stdbool.h> // bool
#include <stdint.h> // uintmax_t

#include <c_utilities/type_generic.h> // TYPE_GENERIC_UNSIGNED_INTEGER_1
#include <c_utilities/types.h> // uint, ullong, ulong

// #define ALL(x) ((x) ^ ~(x))
// #define ALL(x) ((x) | ~(x))
// #define ALL(x) (~NONE(x))
#define IS_POWER_OF_TWO(x) ((x) > 0 && ((x) & ((x) - 1)) == 0)
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

#define isPowerOfTwo(x) TYPE_GENERIC_UNSIGNED_INTEGER_1(isPowerOfTwo, x)

#endif // C_UTILITIES_BIT_H

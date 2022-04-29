#ifndef C_UTILITIES_BIT_H
#define C_UTILITIES_BIT_H

#include <stdbool.h> // bool
#include <stdint.h> // uintmax_t

#include <c_utilities/type_generic.h> // TYPE_GENERIC_UNSIGNED_INTEGER_1
#include <c_utilities/types.h> // uint, ullong, ulong

#define IS_POWER_OF_TWO(x) ((x) != 0 && ((x) & ((x) - 1)) == 0)

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

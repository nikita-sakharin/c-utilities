#ifndef C_UTILITIES_BIT_H
#define C_UTILITIES_BIT_H

#include <stdint.h> // uintmax_t

#include <c_utilities/type_generic.h> // TYPE_GENERIC_UNSIGNED_INTEGER_MACRO_1
#include <c_utilities/types.h> // uint, ullong, ulong

#define HAS_SINGLE_BIT(x) ((x) != 0 && ((x) & ((x) - 1)) == 0)

inline uint uhasSingleBit(register const uint x) {
    return HAS_SINGLE_BIT(x);
}

inline ulong ulhasSingleBit(register const ulong x) {
    return HAS_SINGLE_BIT(x);
}

inline ullong ullhasSingleBit(register const ullong x) {
    return HAS_SINGLE_BIT(x);
}

inline uintmax_t umaxhasSingleBit(register const uintmax_t x) {
    return HAS_SINGLE_BIT(x);
}

#define hasSingleBit(x) \
    TYPE_GENERIC_UNSIGNED_INTEGER_MACRO_1(hasSingleBit, x)

#endif // C_UTILITIES_BIT_H

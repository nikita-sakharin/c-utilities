#include <stdbool.h> // bool
#include <stdint.h> // uintmax_t

#include <c_utilities/bit.h> // *hasSingleBit
#include <c_utilities/types.h> // uint, ullong, ulong

extern inline bool uhasSingleBit(uint);
extern inline bool ulhasSingleBit(ulong);
extern inline bool ullhasSingleBit(ullong);
extern inline bool umaxhasSingleBit(uintmax_t);

#include <stdint.h> // uintmax_t

#include <c_utilities/bit.h> // *hasSingleBit
#include <c_utilities/types.h> // uint, ullong, ulong

extern inline uint uhasSingleBit(uint);
extern inline ulong ulhasSingleBit(ulong);
extern inline ullong ullhasSingleBit(ullong);
extern inline uintmax_t umaxhasSingleBit(uintmax_t);

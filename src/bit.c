#include <stdbool.h> // bool
#include <stdint.h> // uintmax_t

#include <c_utilities/bit.h> // *isPowerOfTwo
#include <c_utilities/types.h> // uint, ullong, ulong

extern inline bool uisPowerOfTwo(uint);
extern inline bool ulisPowerOfTwo(ulong);
extern inline bool ullisPowerOfTwo(ullong);
extern inline bool umaxisPowerOfTwo(uintmax_t);

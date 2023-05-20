#include <stdbool.h> // bool
#include <stdint.h> // intmax_t, uintmax_t

#include <c_commons/bit.h> // *
#include <c_commons/types.h> // llong, uint, ullong, ulong

extern inline bool uisPowerOfTwo(uint);
extern inline bool ulisPowerOfTwo(ulong);
extern inline bool ullisPowerOfTwo(ullong);
extern inline bool umaxisPowerOfTwo(uintmax_t);

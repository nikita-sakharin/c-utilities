#include <stdbool.h> // bool
#include <stdint.h> // intmax_t, uintmax_t

#include <c_utilities/bit.h> // *
#include <c_utilities/types.h> // llong, uint, ullong, ulong

extern inline bool uisPowerOfTwo(uint);
extern inline bool ulisPowerOfTwo(ulong);
extern inline bool ullisPowerOfTwo(ullong);
extern inline bool umaxisPowerOfTwo(uintmax_t);

inline bool isSameSign(int, int);
inline bool lisSameSign(long, long);
inline bool llisSameSign(llong, llong);
inline bool imaxisSameSign(intmax_t, intmax_t);

#include <stdbool.h> // bool
#include <stdint.h> // intmax_t, uintmax_t

#include <c_utilities/bit.h> // *
#include <c_utilities/types.h> // llong, uint, ullong, ulong

extern inline bool (isEven)(int);
extern inline bool uisEven(uint);
extern inline bool lisEven(long);
extern inline bool ulisEven(ulong);
extern inline bool llisEven(llong);
extern inline bool ullisEven(ullong);
extern inline bool imaxisEven(intmax_t);
extern inline bool umaxisEven(uintmax_t);

extern inline bool (isOdd)(int);
extern inline bool uisOdd(uint);
extern inline bool lisOdd(long);
extern inline bool ulisOdd(ulong);
extern inline bool llisOdd(llong);
extern inline bool ullisOdd(ullong);
extern inline bool imaxisOdd(intmax_t);
extern inline bool umaxisOdd(uintmax_t);

extern inline bool uisPowerOfTwo(uint);
extern inline bool ulisPowerOfTwo(ulong);
extern inline bool ullisPowerOfTwo(ullong);
extern inline bool umaxisPowerOfTwo(uintmax_t);

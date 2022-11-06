#include <stdbool.h> // bool
#include <stdint.h> // intmax_t, uintmax_t

#include <c_utilities/arithmetic.h> // *clamp, *dim, *max, *min
#include <c_utilities/types.h> // llong, uint, ullong, ulong

extern inline int (clamp)(int, int, int);
extern inline uint uclamp(uint, uint, uint);
extern inline long lclamp(long, long, long);
extern inline ulong ulclamp(ulong, ulong, ulong);
extern inline llong llclamp(llong, llong, llong);
extern inline ullong ullclamp(ullong, ullong, ullong);
extern inline intmax_t imaxclamp(intmax_t, intmax_t, intmax_t);
extern inline uintmax_t umaxclamp(uintmax_t, uintmax_t, uintmax_t);

extern inline int (dim)(int, int);
extern inline uint udim(uint, uint);
extern inline long ldim(long, long);
extern inline ulong uldim(ulong, ulong);
extern inline llong lldim(llong, llong);
extern inline ullong ulldim(ullong, ullong);
extern inline intmax_t imaxdim(intmax_t, intmax_t);
extern inline uintmax_t umaxdim(uintmax_t, uintmax_t);

extern inline bool (inRange)(int, int, int);
extern inline bool uinRange(uint, uint, uint);
extern inline bool linRange(long, long, long);
extern inline bool ulinRange(ulong, ulong, ulong);
extern inline bool llinRange(llong, llong, llong);
extern inline bool ullinRange(ullong, ullong, ullong);
extern inline bool imaxinRange(intmax_t, intmax_t, intmax_t);
extern inline bool umaxinRange(uintmax_t, uintmax_t, uintmax_t);

extern inline int (max)(int, int);
extern inline uint umax(uint, uint);
extern inline long lmax(long, long);
extern inline ulong ulmax(ulong, ulong);
extern inline llong llmax(llong, llong);
extern inline ullong ullmax(ullong, ullong);
extern inline intmax_t imaxmax(intmax_t, intmax_t);
extern inline uintmax_t umaxmax(uintmax_t, uintmax_t);

extern inline int (min)(int, int);
extern inline uint umin(uint, uint);
extern inline long lmin(long, long);
extern inline ulong ulmin(ulong, ulong);
extern inline llong llmin(llong, llong);
extern inline ullong ullmin(ullong, ullong);
extern inline intmax_t imaxmin(intmax_t, intmax_t);
extern inline uintmax_t umaxmin(uintmax_t, uintmax_t);

extern inline int (sign)(int);
extern inline long lsign(long);
extern inline llong llsign(llong);
extern inline intmax_t imaxsign(intmax_t);

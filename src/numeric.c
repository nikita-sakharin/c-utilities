#include <stdint.h> // intmax_t, uintmax_t

#include <c_commons/numeric.h> // *gcd, *ipow, *lcm
#include <c_commons/types.h> // llong, uint, ullong, ulong

extern inline int (gcd)(int, int);
extern inline uint ugcd(uint, uint);
extern inline long lgcd(long, long);
extern inline ulong ulgcd(ulong, ulong);
extern inline llong llgcd(llong, llong);
extern inline ullong ullgcd(ullong, ullong);
extern inline intmax_t imaxgcd(intmax_t, intmax_t);
extern inline uintmax_t umaxgcd(uintmax_t, uintmax_t);

extern inline int (ipow)(int, uint);
extern inline uint uipow(uint, uint);
extern inline long lipow(long, uint);
extern inline ulong ulipow(ulong, uint);
extern inline llong llipow(llong, uint);
extern inline ullong ullipow(ullong, uint);
extern inline intmax_t imaxipow(intmax_t, uint);
extern inline uintmax_t umaxipow(uintmax_t, uint);

extern inline int (lcm)(int, int);
extern inline uint ulcm(uint, uint);
extern inline long llcm(long, long);
extern inline ulong ullcm(ulong, ulong);
extern inline llong lllcm(llong, llong);
extern inline ullong ulllcm(ullong, ullong);
extern inline intmax_t imaxlcm(intmax_t, intmax_t);
extern inline uintmax_t umaxlcm(uintmax_t, uintmax_t);

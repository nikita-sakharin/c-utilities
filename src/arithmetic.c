#include <stdbool.h> // bool
#include <stdint.h> // intmax_t, uintmax_t

#include <c_utilities/arithmetic.h> // *
#include <c_utilities/types.h> // llong, uint, ullong, ulong

extern inline uint (absDiff)(int, int);
extern inline uint uabsDiff(uint, uint);
extern inline ulong labsDiff(long, long);
extern inline ulong ulabsDiff(ulong, ulong);
extern inline ullong llabsDiff(llong, llong);
extern inline ullong ullabsDiff(ullong, ullong);
extern inline uintmax_t imaxabsDiff(intmax_t, intmax_t);
extern inline uintmax_t umaxabsDiff(uintmax_t, uintmax_t);

extern inline int (ceilDiv)(int, int);
extern inline uint uceilDiv(uint, uint);
extern inline long lceilDiv(long, long);
extern inline ulong ulceilDiv(ulong, ulong);
extern inline llong llceilDiv(llong, llong);
extern inline ullong ullceilDiv(ullong, ullong);
extern inline intmax_t imaxceilDiv(intmax_t, intmax_t);
extern inline uintmax_t umaxceilDiv(uintmax_t, uintmax_t);

extern inline int (ceilMod)(int, int);
extern inline uint uceilMod(uint, uint);
extern inline long lceilMod(long, long);
extern inline ulong ulceilMod(ulong, ulong);
extern inline llong llceilMod(llong, llong);
extern inline ullong ullceilMod(ullong, ullong);
extern inline intmax_t imaxceilMod(intmax_t, intmax_t);
extern inline uintmax_t umaxceilMod(uintmax_t, uintmax_t);

extern inline int (clamp)(int, int, int);
extern inline uint uclamp(uint, uint, uint);
extern inline long lclamp(long, long, long);
extern inline ulong ulclamp(ulong, ulong, ulong);
extern inline llong llclamp(llong, llong, llong);
extern inline ullong ullclamp(ullong, ullong, ullong);
extern inline intmax_t imaxclamp(intmax_t, intmax_t, intmax_t);
extern inline uintmax_t umaxclamp(uintmax_t, uintmax_t, uintmax_t);

extern inline uint (dim)(int, int);
extern inline uint udim(uint, uint);
extern inline ulong ldim(long, long);
extern inline ulong uldim(ulong, ulong);
extern inline ullong lldim(llong, llong);
extern inline ullong ulldim(ullong, ullong);
extern inline uintmax_t imaxdim(intmax_t, intmax_t);
extern inline uintmax_t umaxdim(uintmax_t, uintmax_t);

extern inline int (euclidDiv)(int, int);
extern inline uint ueuclidDiv(uint, uint);
extern inline long leuclidDiv(long, long);
extern inline ulong uleuclidDiv(ulong, ulong);
extern inline llong lleuclidDiv(llong, llong);
extern inline ullong ulleuclidDiv(ullong, ullong);
extern inline intmax_t imaxeuclidDiv(intmax_t, intmax_t);
extern inline uintmax_t umaxeuclidDiv(uintmax_t, uintmax_t);

extern inline int (euclidMod)(int, int);
extern inline uint ueuclidMod(uint, uint);
extern inline long leuclidMod(long, long);
extern inline ulong uleuclidMod(ulong, ulong);
extern inline llong lleuclidMod(llong, llong);
extern inline ullong ulleuclidMod(ullong, ullong);
extern inline intmax_t imaxeuclidMod(intmax_t, intmax_t);
extern inline uintmax_t umaxeuclidMod(uintmax_t, uintmax_t);

extern inline int (floorDiv)(int, int);
extern inline uint ufloorDiv(uint, uint);
extern inline long lfloorDiv(long, long);
extern inline ulong ulfloorDiv(ulong, ulong);
extern inline llong llfloorDiv(llong, llong);
extern inline ullong ullfloorDiv(ullong, ullong);
extern inline intmax_t imaxfloorDiv(intmax_t, intmax_t);
extern inline uintmax_t umaxfloorDiv(uintmax_t, uintmax_t);

extern inline int (floorMod)(int, int);
extern inline uint ufloorMod(uint, uint);
extern inline long lfloorMod(long, long);
extern inline ulong ulfloorMod(ulong, ulong);
extern inline llong llfloorMod(llong, llong);
extern inline ullong ullfloorMod(ullong, ullong);
extern inline intmax_t imaxfloorMod(intmax_t, intmax_t);
extern inline uintmax_t umaxfloorMod(uintmax_t, uintmax_t);

extern inline bool (inRange)(int, int, int);
extern inline bool uinRange(uint, uint, uint);
extern inline bool linRange(long, long, long);
extern inline bool ulinRange(ulong, ulong, ulong);
extern inline bool llinRange(llong, llong, llong);
extern inline bool ullinRange(ullong, ullong, ullong);
extern inline bool imaxinRange(intmax_t, intmax_t, intmax_t);
extern inline bool umaxinRange(uintmax_t, uintmax_t, uintmax_t);

extern inline bool (inRangeClose)(int, int, int);
extern inline bool uinRangeClose(uint, uint, uint);
extern inline bool linRangeClose(long, long, long);
extern inline bool ulinRangeClose(ulong, ulong, ulong);
extern inline bool llinRangeClose(llong, llong, llong);
extern inline bool ullinRangeClose(ullong, ullong, ullong);
extern inline bool imaxinRangeClose(intmax_t, intmax_t, intmax_t);
extern inline bool umaxinRangeClose(uintmax_t, uintmax_t, uintmax_t);

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
extern inline int lsign(long);
extern inline int llsign(llong);
extern inline int imaxsign(intmax_t);

extern inline uint (unsignedAbs)(int);
extern inline ulong lunsignedAbs(long);
extern inline ullong llunsignedAbs(llong);
extern inline uintmax_t imaxunsignedAbs(intmax_t);

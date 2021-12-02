#include <stddef.h> // ptrdiff_t, size_t

#include <c_utilities/common.h> // memSwap, ptrDiff, ptrOffset

extern inline void *memSwap(void * restrict, void * restrict, size_t);

extern inline ptrdiff_t ptrDiff(const void *, const void *, size_t);
extern inline void *ptrOffset(const void *, size_t, size_t);

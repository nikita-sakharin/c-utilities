#include <stddef.h> // ptrdiff_t, size_t

#include <c_utilities/common.h> // arrSwap, memSwap, ptrDifference, ptrOffset

extern inline void *arrSwap(void * restrict, size_t, size_t, size_t);

extern inline void *memSwap(void * restrict, void * restrict, size_t);

extern inline ptrdiff_t ptrDifference(const void *, const void *, size_t);
extern inline void *ptrOffset(const void *, size_t, size_t);

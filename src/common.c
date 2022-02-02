#include <stddef.h> // ptrdiff_t, size_t

#include <c_utilities/common.h> // arr*, mem*, ptr*

extern inline int arrCompare(const void * restrict, size_t, size_t, size_t,
    int (*cmp)(const void *, const void *)
);
extern inline int arrCompareSwap(const void * restrict, size_t, size_t, size_t,
    int (*cmp)(const void *, const void *)
);
extern inline void *arrSwap(void * restrict, size_t, size_t, size_t);

extern inline void *memSwap(void * restrict, void * restrict, size_t);
extern inline bool memCompareSwap(void * restrict, void * restrict, size_t,
    int (*cmp)(const void *, const void *)
);

extern inline ptrdiff_t ptrDifference(const void *, const void *, size_t);
extern inline void *ptrOffset(const void *, size_t, size_t);

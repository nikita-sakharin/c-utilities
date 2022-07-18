#include <stddef.h> // ptrdiff_t, size_t

#include <c_utilities/common.h> // elem*, mem*, ptr*

extern inline int elemCompare(const void * restrict, size_t, size_t, size_t,
    int (*)(const void *, const void *)
);
inline void *elemCompareMax(const void * restrict, size_t, size_t, size_t,
    int (*)(const void *, const void *)
);
inline void *elemCompareMin(const void * restrict, size_t, size_t, size_t,
    int (*)(const void *, const void *)
);
extern inline int elemCompareSwap(const void * restrict, size_t, size_t, size_t,
    int (*)(const void *, const void *)
);
extern inline void *elemSwap(void * restrict, size_t, size_t, size_t);

extern inline void *memSwap(void * restrict, void * restrict, size_t);
extern inline bool memCompareSwap(void * restrict, void * restrict, size_t,
    int (*)(const void *, const void *)
);

extern inline ptrdiff_t ptrDifference(const void *, const void *, size_t);
extern inline void *ptrMidpoint(const void *, const void *, size_t);
extern inline void *ptrOffset(const void *, size_t, size_t);

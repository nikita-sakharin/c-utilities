#include <stddef.h> // ptrdiff_t, size_t

#include <c_utilities/utility.h> // elem*, mem*, ptr*

extern inline void *elemAt(const void *, size_t, size_t);
extern inline int elemCompare(const void * restrict, size_t, size_t,
    size_t, int (*)(const void *, const void *)
);
extern inline void *elemCompareMax(const void * restrict, size_t, size_t,
    size_t, int (*)(const void *, const void *)
);
extern inline void *elemCompareMin(const void * restrict, size_t, size_t,
    size_t, int (*)(const void *, const void *)
);
extern inline bool elemCompareSwap(const void * restrict, size_t, size_t,
    size_t, int (*)(const void *, const void *)
);
extern inline void *elemSwap(void * restrict, size_t, size_t, size_t);

extern inline bool memCompareSwap(void * restrict, void * restrict, size_t,
    int (*)(const void *, const void *)
);
extern inline void *memSwap(void * restrict, void * restrict, size_t);

extern inline int ptrCompare(const void *, const void *);
extern inline ptrdiff_t ptrDifference(const void *, const void *, size_t);
extern inline void *ptrDecrement(const void *, size_t);
extern inline void *ptrIncrement(const void *, size_t);
extern inline void *ptrMax(const void *, const void *);
extern inline void *ptrMin(const void *, const void *);
extern inline void *ptrMidpoint(const void *, const void *, size_t);
extern inline void *ptrOffset(const void *, ptrdiff_t, size_t);

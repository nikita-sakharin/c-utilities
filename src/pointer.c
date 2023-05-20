#include <stddef.h> // ptrdiff_t, size_t

#include <c_commons/pointer.h> // ptr*

extern inline int ptrCompare(const void *, const void *);
extern inline ptrdiff_t ptrDifference(const void *, const void *, size_t);
extern inline void *ptrDecrement(const void *, size_t);
extern inline void *ptrIncrement(const void *, size_t);
extern inline void *ptrMax(const void *, const void *);
extern inline void *ptrMin(const void *, const void *);
extern inline void *ptrMidpoint(const void *, const void *, size_t);
extern inline void *ptrOffset(const void *, ptrdiff_t, size_t);

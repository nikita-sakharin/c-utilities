#ifndef C_UTILITIES_COMMON_H
#define C_UTILITIES_COMMON_H

#include <assert.h> // assert
#include <stdalign.h> // alignas
#include <stdbool.h> // bool, false, true
#include <stddef.h> // NULL, ptrdiff_t, size_t
#include <stdint.h> // PTRDIFF_MAX, PTRDIFF_MIN
#include <stdlib.h> // abs
#include <string.h> // memcpy

#include <c_utilities/arithmetic.h> // abs, inRange, max, min, sign
#include <c_utilities/compare.h> // CMP_LESS
#include <c_utilities/system_config.h> // LEVEL1_DCACHE_LINESIZE
#include <c_utilities/types.h> // uchar

inline void *memCompareMax(
    register const void * const s1,
    register const void * const s2,
    register int (* const cmp)(const void *, const void *)
) {
    assert(s1 != NULL && s2 != NULL && cmp != NULL);
    return cmp(s1, s2) < 0 ? s2 : s1;
}

inline void *memCompareMin(
    register const void * const s1,
    register const void * const s2,
    register int (* const cmp)(const void *, const void *)
) {
    assert(s1 != NULL && s2 != NULL && cmp != NULL);
    return cmp(s1, s2) > 0 ? s2 : s1;
}

inline void *memSwap(
    register void * const restrict s1,
    register void * const restrict s2,
#   ifdef NDEBUG
    register const size_t n
#   else
    register size_t n
#   endif
) {
    assert(s1 != NULL && s2 != NULL && n <= PTRDIFF_MAX &&
        (char *) s1 <= (char *) s1 + n && (char *) s2 <= (char *) s2 + n &&
        ((char *) s1 >= (char *) s2 + n || (char *) s2 >= (char *) s1 + n)
    );
#   ifdef NDEBUG
    register const uchar * const end1 = (uchar *) s1 + n;
    for (register uchar
        * restrict ptr1 = (uchar *) s1, * restrict ptr2 = (uchar *) s2;
        ptr1 < end1; ++ptr1, ++ptr2
    ) {
        register const uchar buffer = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = buffer;
    }
#   else
    for (register uchar
        * restrict ptr1 = (uchar *) s1, * restrict ptr2 = (uchar *) s2; n != 0U;
    ) {
        alignas(LEVEL1_DCACHE_LINESIZE) uchar buffer[LEVEL1_DCACHE_LINESIZE];
        register const size_t offset = min(LEVEL1_DCACHE_LINESIZE, n);
        memcpy(buffer, ptr1, offset);
        memcpy(ptr1, ptr2, offset);
        memcpy(ptr2, buffer, offset);
        n -= offset;
        ptr1 += offset;
        ptr2 += offset;
    }
#   endif // NDEBUG
    return s1;
}

inline bool memCompareSwap(
    register void * const restrict s1,
    register void * const restrict s2,
    register const size_t n,
    register int (* const cmp)(const void *, const void *)
) {
    assert(s1 != NULL && s2 != NULL && n <= PTRDIFF_MAX && cmp != NULL &&
        (char *) s1 <= (char *) s1 + n && (char *) s2 <= (char *) s2 + n &&
        ((char *) s1 >= (char *) s2 + n || (char *) s2 >= (char *) s1 + n)
    );
    if (cmp(s1, s2) <= 0)
        return false;
    memSwap(s1, s2, n);
    return true;
}

inline ptrdiff_t ptrDifference(
    register const void * const ptr1,
    register const void * const ptr2,
    register const size_t size
) {
    assert((ptr1 == NULL) == (ptr2 == NULL) && inRange(size, 1U, PTRDIFF_MAX) &&
        (const char *) ptr1 - (const char *) ptr2 != PTRDIFF_MIN &&
        sign((const char *) ptr1 - (const char *) ptr2) == CMP_LESS(ptr1, ptr2) &&
        ((const char *) ptr1 - (const char *) ptr2) % (ptrdiff_t) size == 0
    );
    return ((const char *) ptr1 - (const char *) ptr2) / (ptrdiff_t) size;
}

inline void *ptrOffset(
    register const void * const ptr,
    register const ptrdiff_t idx,
    register const size_t size
) {
    assert((ptr != NULL || idx == 0) && inRange(size, 1U, PTRDIFF_MAX) &&
        idx != PTRDIFF_MIN && abs(idx) <= PTRDIFF_MAX / (ptrdiff_t) size &&
        sign(idx) == CMP_LESS((const char *) ptr, (const char *) ptr + idx * size) &&
        (ptr == NULL || (const char *) ptr + idx * size != NULL)
    );
#   ifdef __clang__
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wcast-qual"
#   elifdef __GNUC__
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wcast-qual"
#   endif
    return (char *) ptr + idx * size;
#   ifdef __clang__
#   pragma clang diagnostic pop
#   elifdef __GNUC__
#   pragma GCC diagnostic pop
#   endif
}

inline void *ptrDecrement(
    register const void * const ptr,
    register const size_t size
) {
    assert(ptr != NULL && inRange(size, 1U, PTRDIFF_MAX) &&
        (const char *) ptr - size < (const char *) ptr &&
        (const char *) ptr - size != NULL
    );
    return ptrOffset(ptr, -1, size);
}

inline void *ptrIncrement(
    register const void * const ptr,
    register const size_t size
) {
    assert(ptr != NULL && inRange(size, 1U, PTRDIFF_MAX) &&
        (const char *) ptr < (const char *) ptr + size
    );
    return ptrOffset(ptr, 1, size);
}

/* inline void *ptrMax(
    register const void * const ptr1,
    register const void * const ptr2,
) {
    assert((ptr1 == NULL) == (ptr2 == NULL) &&
        (const char *) ptr1 - (const char *) ptr2 != PTRDIFF_MIN &&
        sign((const char *) ptr1 - (const char *) ptr2) == CMP_LESS(ptr1, ptr2)
    );
    return ;
}

inline void *ptrMin(
    register const void * const ptr1,
    register const void * const ptr2,
) {
    assert((ptr1 == NULL) == (ptr2 == NULL) &&
        (const char *) ptr1 - (const char *) ptr2 != PTRDIFF_MIN &&
        sign((const char *) ptr1 - (const char *) ptr2) == CMP_LESS(ptr1, ptr2)
    );
    return ;
} */

inline void *ptrMidpoint(
    register const void * const ptr1,
    register const void * const ptr2,
    register const size_t size
) {
    assert((ptr1 == NULL) == (ptr2 == NULL) && inRange(size, 1U, PTRDIFF_MAX) &&
        (const char *) ptr1 - (const char *) ptr2 != PTRDIFF_MIN &&
        sign((const char *) ptr1 - (const char *) ptr2) == CMP_LESS(ptr1, ptr2) &&
        ((const char *) ptr1 - (const char *) ptr2) % (ptrdiff_t) size == 0
    );
    return ptrOffset(ptr1, ptrDifference(ptr2, ptr1, size) >> 1U, size);
}

/* inline void *arrayMidpoint(
    register const void * const restrict arr,
    register const size_t n, // ???
    register const size_t size
) { // n != 0 ???
    assert(arr != NULL && n < PTRDIFF_MAX && inRange(size, 1U, PTRDIFF_MAX) &&
        n <= PTRDIFF_MAX / size &&
        (const char *) arr <= (const char *) arr + n * size
    );
    return elemAt(arr, n >> 1U, size);
} */

inline void *elemAt( // elemAtIndex ???
    register const void * const arr,
    register const size_t idx,
    register const size_t size
) {
    assert(arr != NULL && inRange(size, 1U, PTRDIFF_MAX) &&
        idx < PTRDIFF_MAX / size &&
        (const char *) arr < (const char *) arr + (idx + 1U) * size
    );
    return ptrOffset(arr, (ptrdiff_t) idx, size);
}

inline int elemCompare(
    register const void * const restrict arr,
    register const size_t idx1,
    register const size_t idx2,
    register const size_t size,
    register int (* const cmp)(const void *, const void *)
) {
    assert(arr != NULL && inRange(size, 1U, PTRDIFF_MAX) &&
        max(idx1, idx2) < PTRDIFF_MAX / size && cmp != NULL &&
        (const char *) arr < (const char *) arr + (max(idx1, idx2) + 1U) * size
    );
    return cmp(elemAt(arr, idx1, size), elemAt(arr, idx2, size));
}

inline void *elemCompareMax(
    register const void * const restrict arr,
    register const size_t idx1,
    register const size_t idx2,
    register const size_t size,
    register int (* const cmp)(const void *, const void *)
) {
    assert(arr != NULL && inRange(size, 1U, PTRDIFF_MAX) &&
        max(idx1, idx2) < PTRDIFF_MAX / size && cmp != NULL &&
        (const char *) arr < (const char *) arr + (max(idx1, idx2) + 1U) * size
    );
    return memCompareMax(elemAt(arr, idx1, size), elemAt(arr, idx2, size), cmp);
}

inline void *elemCompareMin(
    register const void * const restrict arr,
    register const size_t idx1,
    register const size_t idx2,
    register const size_t size,
    register int (* const cmp)(const void *, const void *)
) {
    assert(arr != NULL && inRange(size, 1U, PTRDIFF_MAX) &&
        max(idx1, idx2) < PTRDIFF_MAX / size && cmp != NULL &&
        (const char *) arr < (const char *) arr + (max(idx1, idx2) + 1U) * size
    );
    return memCompareMin(elemAt(arr, idx1, size), elemAt(arr, idx2, size), cmp);
}

inline bool elemCompareSwap(
    register void * const restrict arr,
    register const size_t idx1,
    register const size_t idx2,
    register const size_t size,
    register int (* const cmp)(const void *, const void *)
) {
    assert(arr != NULL && idx1 != idx2 && inRange(size, 1U, PTRDIFF_MAX) &&
        max(idx1, idx2) < PTRDIFF_MAX / size && cmp != NULL &&
        (char *) arr < (char *) arr + (max(idx1, idx2) + 1U) * size
    );
    return memCompareSwap(
        elemAt(arr, idx1, size), elemAt(arr, idx2, size), cmp
    );
}

inline void *elemSwap(
    register void * const restrict arr,
    register const size_t idx1,
    register const size_t idx2,
    register const size_t size
) {
    assert(arr != NULL && idx1 != idx2 && inRange(size, 1U, PTRDIFF_MAX) &&
        max(idx1, idx2) < PTRDIFF_MAX / size &&
        (char *) arr < (char *) arr + (max(idx1, idx2) + 1U) * size
    );
    return memSwap(elemAt(arr, idx1, size), elemAt(arr, idx2, size));
}

#endif // C_UTILITIES_COMMON_H

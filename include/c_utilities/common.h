#ifndef C_UTILITIES_COMMON_H
#define C_UTILITIES_COMMON_H

#include <assert.h> // assert
#include <stdalign.h> // alignas
#include <stdbool.h> // bool, false, true
#include <stddef.h> // NULL, ptrdiff_t, size_t
#include <stdint.h> // PTRDIFF_MAX
#include <string.h> // memcpy

#include <c_utilities/arithmetic.h> // max, min
#include <c_utilities/system_config.h> // LEVEL1_DCACHE_LINESIZE
#include <c_utilities/types.h> // uchar
// arrCompareMax or arrMax
// ptrCompareMax or ptrMax

inline int arrCompare(
    register const void * const restrict arr,
    register const size_t idx1,
    register const size_t idx2,
    register const size_t size,
    register int (* const cmp)(const void *, const void *)
) {
    assert(arr != NULL && size > 0U && size <= PTRDIFF_MAX &&
        max(idx1, idx2) <= PTRDIFF_MAX / size - 1U && cmp != NULL
    );
    return cmp(ptrOffset(arr, idx1, size), ptrOffset(arr, idx2, size));
}

inline bool arrCompareSwap(
    register void * const restrict arr,
    register const size_t idx1,
    register const size_t idx2,
    register const size_t size,
    register int (* const cmp)(const void *, const void *)
) {
    assert(arr != NULL && size > 0U && size <= PTRDIFF_MAX &&
        max(idx1, idx2) <= PTRDIFF_MAX / size - 1U && cmp != NULL
    );
    return memCompareSwap(
        ptrOffset(arr, idx1, size), ptrOffset(arr, idx2, size), cmp
    );
}

inline void *arrSwap(
    register void * const restrict arr,
    register const size_t idx1,
    register const size_t idx2,
    register const size_t size
) {
    assert(arr != NULL && idx1 != idx2 && size > 0U && size <= PTRDIFF_MAX &&
        max(idx1, idx2) <= PTRDIFF_MAX / size - 1U
    );
    return memSwap(ptrOffset(arr, idx1, size), ptrOffset(arr, idx2, size));
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
        * restrict ptr1 = (uchar *) s1, * restrict ptr2 = (uchar *) s2;
        n > 0;
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
    assert(s1 != NULL && s2 != NULL && n <= PTRDIFF_MAX &&
        (char *) s1 <= (char *) s1 + n && (char *) s2 <= (char *) s2 + n &&
        ((char *) s1 >= (char *) s2 + n || (char *) s2 >= (char *) s1 + n)
        cmp != NULL
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
    assert(ptr1 == NULL == (ptr2 == NULL) && size > 0U && size <= PTRDIFF_MAX &&
        // COMPARE_LESS(ptr1, ptr2) == clamp((const char *) ptr1 - (const char *) ptr2, -1, 1) &&
        (ptr1 <= ptr2 || (const char *) ptr1 - (const char *) ptr2 >= 0) &&
        (ptr1 >= ptr2 || (const char *) ptr1 - (const char *) ptr2 <= 0) &&
        ((const char *) ptr1 - (const char *) ptr2) % (ptrdiff_t) size == 0
    );
    return ((const char *) ptr1 - (const char *) ptr2) / (ptrdiff_t) size;
}

inline void *ptrOffset(
    register const void * const ptr,
    register const size_t idx,
    register const size_t size
) {
    assert((ptr != NULL || idx == 0U) && size > 0U && size <= PTRDIFF_MAX &&
        idx <= PTRDIFF_MAX / size &&
        (const char *) ptr <= (const char *) ptr + idx * size
    );
#   if defined(__clang__)
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wcast-qual"
#   elif defined(__GNUC__)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wcast-qual"
#   endif
    return (char *) ptr + idx * size;
#   if defined(__clang__)
#   pragma clang diagnostic pop
#   elif defined(__GNUC__)
#   pragma GCC diagnostic pop
#   endif
}

#endif // C_UTILITIES_COMMON_H

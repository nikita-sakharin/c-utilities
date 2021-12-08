#ifndef C_UTILITIES_COMMON_H
#define C_UTILITIES_COMMON_H

#include <assert.h> // assert
#include <stdalign.h> // alignas
#include <stdbool.h> // bool, false, true
#include <stddef.h> // NULL, ptrdiff_t, size_t
#include <stdint.h> // PTRDIFF_MAX
#include <string.h> // memcpy

#include <c_utilities/arithmetic.h> // max
#include <c_utilities/system_config.h> // LEVEL1_DCACHE_LINESIZE
#include <c_utilities/types.h> // uchar
// arr_compare_max or arr_max
// ptr_compare_max or ptr_max

// restrict ???
inline int arrCompare(
    register const void * const restrict arr,
    register const size_t index1,
    register const size_t index2,
    register const size_t size,
    register int (* const compare)(const void *, const void *)
) {
    assert(arr != NULL && size > 0U && size <= PTRDIFF_MAX &&
        max(index1, index2) + 1U <= PTRDIFF_MAX / size && compare != NULL
    );
    return compare(ptrOffset(arr, index1, size), ptrOffset(arr, index2, size));
}

inline bool arrCompareSwap(
    register void * const restrict arr,
    register const size_t index1,
    register const size_t index2,
    register const size_t size,
    register int (* const compare)(const void *, const void *)
) {
    assert(arr != NULL && size > 0U && size <= PTRDIFF_MAX &&
        max(index1, index2) + 1U <= PTRDIFF_MAX / size && compare != NULL
    );
    if (arrCompare(arr, index1, index2, size, compare) <= 0)
        return false;
    arrSwap(arr, index1, index2, size);
    return true;
}

inline void *arrSwap(
    register void * const restrict arr,
    register const size_t index1,
    register const size_t index2,
    register const size_t size
) {
    assert(arr != NULL && index1 != index2 && size > 0U &&
        size <= PTRDIFF_MAX && max(index1, index2) + 1U <= PTRDIFF_MAX / size
    );
    return memSwap(ptrOffset(arr, index1, size), ptrOffset(arr, index2, size));
}

inline void *memSwap(
    void * const restrict s1,
    void * const restrict s2,
    register size_t n
) {
    assert(s1 != NULL && s2 != NULL && n <= PTRDIFF_MAX &&
        (uchar *) s1 < (uchar *) s1 + n + 1U &&
        (uchar *) s2 < (uchar *) s2 + n + 1U &&
        ((uchar *) s1 >= (uchar *) s2 + n || (uchar *) s2 >= (uchar *) s1 + n)
    );
#   ifdef NDEBUG
    for (register uchar
        * restrict ptr1 = (uchar *) s1, * restrict ptr2 = (uchar *) s2;
        n > 0; --n, ++ptr1, ++ptr2
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

// restrict ???
inline ptrdiff_t ptrDifference(
    register const void * const ptr1,
    register const void * const ptr2,
    register const size_t size
) {
    assert(ptr1 != NULL == (ptr2 != NULL) && size > 0U && size <= PTRDIFF_MAX &&
        ((const char *) ptr1 - (const char *) ptr2) % (ptrdiff_t) size == 0
    );
    return ((const char *) ptr1 - (const char *) ptr2) / (ptrdiff_t) size;
}

inline void *ptrOffset(
    register const void * const ptr,
    register const size_t index,
    register const size_t size
) {
    assert((ptr != NULL || index == 0U) && size > 0U && size <= PTRDIFF_MAX &&
        index <= PTRDIFF_MAX / size && (const char *) ptr <= (const char *) ptr + index * size
    );
#   if defined(__clang__)
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wcast-qual"
#   elif defined(__GNUC__)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wcast-qual"
#   endif
    return (char *) ptr + index * size;
#   if defined(__clang__)
#   pragma clang diagnostic pop
#   elif defined(__GNUC__)
#   pragma GCC diagnostic pop
#   endif
}

#endif // C_UTILITIES_COMMON_H

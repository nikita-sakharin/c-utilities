#ifndef C_UTILITIES_COMMON_H
#define C_UTILITIES_COMMON_H

#include <stdalign.h> // alignas
#include <stdbool.h> // bool
#include <stddef.h> // ptrdiff_t, size_t
#include <string.h> // memcpy

#include "c_utilities/arithmetic.h"
#include "c_utilities/system_config.h"
#include "c_utilities/types.h"

// restrict ???
inline int arr_compare(
    register const void * const restrict arr,
    register const size_t index1,
    register const size_t index2,
    register const size_t size,
    register int (* const compare)(const void *, const void *)
) {
    return compare(
        ptr_offset(arr, index1, size),
        ptr_offset(arr, index2, size)
    );
}

inline bool arr_compare_swap(
    register void * const restrict arr,
    register const size_t index1,
    register const size_t index2,
    register const size_t size,
    register int (* const compare)(const void *, const void *)
) {
    if (arr_compare(arr, index1, index2, size, compare) <= 0)
        return false;
    arr_swap(arr, index1, index2, size);
    return true;
}

inline void *arr_swap(
    register void * const restrict arr,
    register const size_t index1,
    register const size_t index2,
    register const size_t size
) {
    return mem_swap(
        ptr_offset(arr, index1, size),
        ptr_offset(arr, index2, size)
    );
}

inline void *mem_swap(
    void * const restrict s1,
    void * const restrict s2,
    register size_t n
) {
#   ifdef NDEBUG
    for (register uchar
        * restrict ptr1 = (uchar *) s1, * restrict ptr2 = (uchar *) s2;
        n-- > 0; ++ptr1, ++ptr2
    ) {
        register const uchar buffer = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = buffer;
    }
#   else
    alignas(CACHE_LINE_SIZE) uchar buffer[CACHE_LINE_SIZE];
    for (register uchar
        * restrict ptr1 = (uchar *) s1, * restrict ptr2 = (uchar *) s2;
        n > 0;
    ) {
        register const size_t offset = min(CACHE_LINE_SIZE, n);
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
inline ptrdiff_t ptr_diff(
    register const void * const ptr1,
    register const void * const ptr2,
    register const size_t size
) {
    return ((const char *) ptr1 - (const char *) ptr2) / (ptrdiff_t) size;
}

inline void *ptr_offset(
    register const void * const ptr,
    register const size_t index,
    register const size_t size
) {
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

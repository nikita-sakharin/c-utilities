#ifndef C_UTILITIES_BINARY_SEARCH_H
#define C_UTILITIES_BINARY_SEARCH_H

#include <stddef.h> // NULL, size_t

#include <c_utilities/common.h> // ptrOffset

inline void *binary_search(
    register const void * const key,
    register const void *array,
    register size_t count,
    register const size_t size,
    register int (* const cmp)(const void *, const void *)
) {
    while (count != 0U) {
        register const size_t step = count / 2U;
        register const void * const midpoint = ptrOffset(array, step, size);
        register const int result = cmp(key, midpoint);
        if (result < 0)
            count = step;
        else if (result > 0) {
            array = ptrOffset(midpoint, 1U, size);
            count -= step + 1U;
        } else
            return midpoint;
    }
    return NULL;
}

#endif // C_UTILITIES_BINARY_SEARCH_H

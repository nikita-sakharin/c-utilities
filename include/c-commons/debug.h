#ifndef C_COMMONS_DEBUG_H
#define C_COMMONS_DEBUG_H

#include <stdbool.h> // bool
#include <stddef.h> // NULL, ptrdiff_t, size_t
#include <stdint.h> // PTRDIFF_MAX, PTRDIFF_MIN

#include <c_commons/arithmetic.h> // inRangeClosed

// isMemory
inline bool checkMemory(
    register const void * const src,
    register const size_t n
) {
    return src != NULL && n <= PTRDIFF_MAX &&
        (const char *) src <= (const char *) src + n;
}

// isMemoryCompare
inline bool checkMemoryCompare(
    register const void * const src,
    register const size_t n,
    register int (* const compare)(const void *, const void *)
) {
    return checkMemory(src, n) && compare != NULL;
}

// isSize
inline bool checkSize(register const size_t size) {
    return inRangeClosed(size, 1U, PTRDIFF_MAX);
}

#endif // C_COMMONS_DEBUG_H

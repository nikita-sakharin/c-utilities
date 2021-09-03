#ifndef C_UTILITIES_SYSTEM_CONFIG_H
#define C_UTILITIES_SYSTEM_CONFIG_H

#include <stddef.h> // max_align_t

#define CACHE_LINE_SIZE (64U)
static_assert(
    CACHE_LINE_SIZE >= alignof(max_align_t),
    "CACHE_LINE_SIZE must be greater or equal than alignof(max_align_t)"
);

#define PAGE_SIZE (4096U)

#endif // C_UTILITIES_SYSTEM_CONFIG_H

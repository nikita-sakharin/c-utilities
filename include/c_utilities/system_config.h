#ifndef C_UTILITIES_SYSTEM_CONFIG_H
#define C_UTILITIES_SYSTEM_CONFIG_H

#include <stdalign.h> // alignof
#include <stddef.h> // max_align_t, ptrdiff_t
#include <stdint.h> // PTRDIFF_MAX

#include <c_utilities/bit.h> // HAS_SINGLE_BIT

#ifndef LEVEL1_DCACHE_LINESIZE
#define LEVEL1_DCACHE_LINESIZE (64U)
#endif
static_assert(
    HAS_SINGLE_BIT(LEVEL1_DCACHE_LINESIZE) &&
        (LEVEL1_DCACHE_LINESIZE) >= (ptrdiff_t) alignof(max_align_t) &&
        (LEVEL1_DCACHE_LINESIZE) <= PTRDIFF_MAX,
    "LEVEL1_DCACHE_LINESIZE must be power of two and "
    "be greater than or equal to alignof(max_align_t)"
);

#ifndef LEVEL1_ICACHE_LINESIZE
#define LEVEL1_ICACHE_LINESIZE (64U)
#endif
static_assert(
    HAS_SINGLE_BIT(LEVEL1_ICACHE_LINESIZE) &&
        (LEVEL1_ICACHE_LINESIZE) >= (ptrdiff_t) alignof(max_align_t) &&
        (LEVEL1_ICACHE_LINESIZE) <= PTRDIFF_MAX,
    "LEVEL1_ICACHE_LINESIZE must be power of two and "
    "be greater than or equal to alignof(max_align_t)"
);

#ifndef LEVEL2_CACHE_LINESIZE
#define LEVEL2_CACHE_LINESIZE (64U)
#endif
static_assert(
    HAS_SINGLE_BIT(LEVEL2_CACHE_LINESIZE) &&
        (LEVEL2_CACHE_LINESIZE) >= (ptrdiff_t) alignof(max_align_t) &&
        (LEVEL2_CACHE_LINESIZE) <= PTRDIFF_MAX,
    "LEVEL2_CACHE_LINESIZE must be power of two and "
    "be greater than or equal to alignof(max_align_t)"
);

#ifndef LEVEL3_CACHE_LINESIZE
#define LEVEL3_CACHE_LINESIZE (64U)
#endif
static_assert(
    LEVEL3_CACHE_LINESIZE == 0U || (
        HAS_SINGLE_BIT(LEVEL3_CACHE_LINESIZE) &&
        LEVEL3_CACHE_LINESIZE >= (ptrdiff_t) alignof(max_align_t) &&
        LEVEL3_CACHE_LINESIZE <= PTRDIFF_MAX
    ),
    "LEVEL3_CACHE_LINESIZE must be power of two and "
    "be greater than or equal to alignof(max_align_t)"
);

#ifndef LEVEL4_CACHE_LINESIZE
#define LEVEL4_CACHE_LINESIZE (0U)
#endif
static_assert(
    LEVEL4_CACHE_LINESIZE == 0U || (
        HAS_SINGLE_BIT(LEVEL4_CACHE_LINESIZE) &&
        LEVEL4_CACHE_LINESIZE >= (ptrdiff_t) alignof(max_align_t) &&
        LEVEL4_CACHE_LINESIZE <= PTRDIFF_MAX
    ),
    "LEVEL4_CACHE_LINESIZE must be power of two and "
    "be greater than or equal to alignof(max_align_t)"
);

static_assert(
    (bool) LEVEL3_CACHE_LINESIZE >= (bool) LEVEL4_CACHE_LINESIZE,
    ""
);

#define PAGE_SIZE (4096U)
#define PAGESIZE PAGE_SIZE
static_assert(
    HAS_SINGLE_BIT(PAGE_SIZE) &&
        PAGE_SIZE >= (ptrdiff_t) alignof(max_align_t) && PAGE_SIZE == PAGESIZE,
    "PAGE_SIZE must be power of two and "
    "be greater than or equal to alignof(max_align_t)"
);

#endif // C_UTILITIES_SYSTEM_CONFIG_H

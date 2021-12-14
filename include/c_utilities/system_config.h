#ifndef C_UTILITIES_SYSTEM_CONFIG_H
#define C_UTILITIES_SYSTEM_CONFIG_H

#include <assert.h> // static_assert
#include <stdalign.h> // alignof
#include <stddef.h> // max_align_t, ptrdiff_t, size_t
#include <stdint.h> // PTRDIFF_MAX

#include <c_utilities/bit.h> // HAS_SINGLE_BIT
#include <c_utilities/types.h> // uint

#ifndef LEVEL1_DCACHE_LINESIZE
#define LEVEL1_DCACHE_LINESIZE (64U)
#endif
static_assert(
    LEVEL1_DCACHE_LINESIZE >= (ptrdiff_t) alignof(max_align_t) &&
        LEVEL1_DCACHE_LINESIZE <= PTRDIFF_MAX &&
        HAS_SINGLE_BIT(LEVEL1_DCACHE_LINESIZE),
    "LEVEL1_DCACHE_LINESIZE shall be a power of 2, "
    "not less than alignof(max_align_t) and not greater than PTRDIFF_MAX"
);

#ifndef LEVEL1_ICACHE_LINESIZE
#define LEVEL1_ICACHE_LINESIZE (64U)
#endif
static_assert(
    LEVEL1_ICACHE_LINESIZE >= (ptrdiff_t) alignof(max_align_t) &&
        LEVEL1_ICACHE_LINESIZE <= PTRDIFF_MAX &&
        HAS_SINGLE_BIT(LEVEL1_ICACHE_LINESIZE),
    "LEVEL1_ICACHE_LINESIZE shall be a power of 2, "
    "not less than alignof(max_align_t) and not greater than PTRDIFF_MAX"
);

#ifndef LEVEL2_CACHE_LINESIZE
#define LEVEL2_CACHE_LINESIZE (64U)
#endif
static_assert(
    LEVEL2_CACHE_LINESIZE >= (ptrdiff_t) alignof(max_align_t) &&
        LEVEL2_CACHE_LINESIZE <= PTRDIFF_MAX &&
        HAS_SINGLE_BIT(LEVEL2_CACHE_LINESIZE),
    "LEVEL2_CACHE_LINESIZE shall be a power of 2, "
    "not less than alignof(max_align_t) and not greater than PTRDIFF_MAX"
);

#ifndef LEVEL3_CACHE_LINESIZE
#define LEVEL3_CACHE_LINESIZE (64U)
#endif
static_assert(
    LEVEL3_CACHE_LINESIZE == 0U || (
        LEVEL3_CACHE_LINESIZE >= (ptrdiff_t) alignof(max_align_t) &&
        LEVEL3_CACHE_LINESIZE <= PTRDIFF_MAX &&
        HAS_SINGLE_BIT(LEVEL3_CACHE_LINESIZE)
    ),
    "LEVEL3_CACHE_LINESIZE shall either be equal to 0 or be a power of 2, "
    "not less than alignof(max_align_t) and not greater than PTRDIFF_MAX"
);

#ifndef LEVEL4_CACHE_LINESIZE
#define LEVEL4_CACHE_LINESIZE (0U)
#endif
static_assert(
    LEVEL4_CACHE_LINESIZE == 0U || (LEVEL3_CACHE_LINESIZE > 0U &&
        LEVEL4_CACHE_LINESIZE >= (ptrdiff_t) alignof(max_align_t) &&
        LEVEL4_CACHE_LINESIZE <= PTRDIFF_MAX &&
        HAS_SINGLE_BIT(LEVEL4_CACHE_LINESIZE)
    ),
    "LEVEL4_CACHE_LINESIZE shall either be equal to 0 or be a power of 2, "
    "not less than alignof(max_align_t) and not greater than PTRDIFF_MAX. "
    "if LEVEL3_CACHE_LINESIZE is equal to 0, "
    "then LEVEL4_CACHE_LINESIZE shall be equal to 0 too"
);

// extern ???
// size_t or uint ???
extern uint nprocessorsConf(void);
extern uint nprocessorsOnln(void);
extern size_t pageSize(void);

#endif // C_UTILITIES_SYSTEM_CONFIG_H

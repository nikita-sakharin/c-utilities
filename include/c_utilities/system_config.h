#ifndef C_UTILITIES_SYSTEM_CONFIG_H
#define C_UTILITIES_SYSTEM_CONFIG_H

#include <assert.h> // static_assert
#include <stdalign.h> // alignof
#include <stddef.h> // max_align_t, ptrdiff_t, size_t
#include <stdint.h> // PTRDIFF_MAX

#ifdef _WIN32
#include <sysinfoapi.h> // GetSystemInfo, SYSTEM_INFO
#else
#include <unistd.h> // _SC_NPROCESSORS_ONLN, sysconf
#endif // _WIN32

#include <c_utilities/bit.h> // HAS_SINGLE_BIT

#ifndef LEVEL1_DCACHE_LINESIZE
#define LEVEL1_DCACHE_LINESIZE (64U)
#endif
static_assert(
    LEVEL1_DCACHE_LINESIZE >= (ptrdiff_t) alignof(max_align_t) &&
        LEVEL1_DCACHE_LINESIZE <= PTRDIFF_MAX &&
        HAS_SINGLE_BIT(LEVEL1_DCACHE_LINESIZE),
    "LEVEL1_DCACHE_LINESIZE must be a power of 2, "
    "not less than alignof(max_align_t) and not greater than PTRDIFF_MAX"
);

#ifndef LEVEL1_ICACHE_LINESIZE
#define LEVEL1_ICACHE_LINESIZE (64U)
#endif
static_assert(
    LEVEL1_ICACHE_LINESIZE >= (ptrdiff_t) alignof(max_align_t) &&
        LEVEL1_ICACHE_LINESIZE <= PTRDIFF_MAX &&
        HAS_SINGLE_BIT(LEVEL1_ICACHE_LINESIZE),
    "LEVEL1_ICACHE_LINESIZE must be a power of 2, "
    "not less than alignof(max_align_t) and not greater than PTRDIFF_MAX"
);

#ifndef LEVEL2_CACHE_LINESIZE
#define LEVEL2_CACHE_LINESIZE (64U)
#endif
static_assert(
    LEVEL2_CACHE_LINESIZE >= (ptrdiff_t) alignof(max_align_t) &&
        LEVEL2_CACHE_LINESIZE <= PTRDIFF_MAX &&
        HAS_SINGLE_BIT(LEVEL2_CACHE_LINESIZE),
    "LEVEL2_CACHE_LINESIZE must be a power of 2, "
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
    "LEVEL3_CACHE_LINESIZE must either be equal to 0 or be a power of 2, "
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
    "LEVEL4_CACHE_LINESIZE must either be equal to 0 or be a power of 2, "
    "not less than alignof(max_align_t) and not greater than PTRDIFF_MAX. "
    "if LEVEL3_CACHE_LINESIZE is equal to 0, "
    "then LEVEL4_CACHE_LINESIZE must be equal to 0 too"
);

inline size_t nprocessorssConf(void) {
#ifdef _WIN32
    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);
    return (size_t) systemInfo.dwNumberOfProcessors;
#else
    register const long returns = sysconf(_SC_NPROCESSORS_CONF);
    return returns < 0 ? 0U : (size_t) returns;
#endif
}

inline size_t nprocessorsOnln(void) {
#ifdef _WIN32
    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);
    return (size_t) systemInfo.dwNumberOfProcessors;
#else
    register const long returns = sysconf(_SC_NPROCESSORS_ONLN);
    return returns < 0 ? 0U : (size_t) returns;
#endif
}

#endif // C_UTILITIES_SYSTEM_CONFIG_H

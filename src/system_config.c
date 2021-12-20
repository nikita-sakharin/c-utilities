#include <assert.h> // assert
#include <stdalign.h> // alignof
#include <stddef.h> // max_align_t, ptrdiff_t, size_t
#include <stdint.h> // SIZE_MAX

#ifdef _WIN32
#include <sysinfoapi.h> // GetSystemInfo, SYSTEM_INFO
#else
#include <unistd.h> // _SC_NPROCESSORS_*, _SC_PAGESIZE, sysconf
#endif // _WIN32

#include <c_utilities/bit.h> // hasSingleBit
#include <c_utilities/system_config.h> // nprocessors*,
#include <c_utilities/types.h> // uint, ulong

// int or uint ???
extern uint nprocessorsConf(void) {
    // static uint returns = 0U;
#ifdef _WIN32
    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);
    return (uint) systemInfo.dwNumberOfProcessors;
#else
    register const long returns = sysconf(_SC_NPROCESSORS_CONF);
    return returns < 0 ? 0U : (uint) returns;
#endif
}

extern uint nprocessorsOnln(void) {
    // static uint returns = 0U;
#ifdef _WIN32
    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);
    return (uint) systemInfo.dwNumberOfProcessors;
#else
    register const long returns = sysconf(_SC_NPROCESSORS_ONLN);
    return returns < 0 ? 0U : (uint) returns;
#endif
}

// pagesize ???
extern size_t pageSize(void) {
    static size_t returns = 0U;
    if (returns != 0)
        return returns;
#ifdef _WIN32
#else
    register const long value = sysconf(_SC_PAGESIZE); // _SC_PAGE_SIZE ???
    assert(value >= (ptrdiff_t) alignof(max_align_t) &&
        (ulong) value <= SIZE_MAX && hasSingleBit((ulong) value)
    );
    returns = value < 0 ? 0U : (size_t) value;
#endif // _WIN32
    return returns;
}

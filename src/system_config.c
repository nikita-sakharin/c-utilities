#include <assert.h> // assert
#include <stddef.h> // size_t
#include <stdint.h> // SIZE_MAX

#ifdef _WIN32
#include <sysinfoapi.h> // GetSystemInfo, SYSTEM_INFO
#else
#include <unistd.h> // _SC_NPROCESSORS_*, _SC_PAGESIZE, sysconf
#endif // _WIN32

#include <c_utilities/bit.h> // hasSingleBit
#include <c_utilities/system_config.h> // ???
#include <c_utilities/types.h> // uint

// int or uint ???
uint nprocessorssConf(void) {
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

uint nprocessorsOnln(void) {
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

// ptrdiff_t or size_t
// pagesize ???
size_t pageSize(void) {
    static size_t returns = 0U;
    if (returns != 0)
        return returns;
#ifdef _WIN32
#else
    register const long value = sysconf(_SC_PAGESIZE); // _SC_PAGE_SIZE ???
    assert((value >= 1 && value <= SIZE_MAX && hasSingleBit(value)) ||
        value == -1
    );
    returns = value < 0 ? 0U : (size_t) value;
#endif // _WIN32
    return returns;
}

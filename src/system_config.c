#include <stddef.h> // size_t

#ifdef _WIN32
#include <sysinfoapi.h> // GetSystemInfo, SYSTEM_INFO
#else
#include <unistd.h> // _SC_NPROCESSORS_*, sysconf
#endif // _WIN32

#include <c_utilities/system_config.h> // ???
#include <c_utilities/types.h> // uint

// size_t or uint ???
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

size_t pageSize(void) {
    // static size_t returns = 0U;
#ifdef _WIN32
#else
    register const long returns = sysconf(_SC_PAGE_SIZE); // _SC_PAGESIZE ???
    return returns < 0 ? 0U : (size_t) returns;
#endif
}

#ifndef C_UTILITIES_NUMERIC_H
#define C_UTILITIES_NUMERIC_H

#include <assert.h> // assert
#include <limits.h> // *_MAX, *_MIN
#include <stdint.h> // intmax_t, uintmax_t

#include <c_commons/arithmetic.h> // inClosedRange, max, min
#include <c_commons/bit.h> // isOdd
#include <c_commons/type_generic.h> // TYPE_GENERIC_INTEGER_*
#include <c_commons/types.h> // llong, uint, ullong, ulong

// binaryGcd, modInverse, modPow
inline int gcd(register int a, register int b) {
    while (b != 0) {
        a %= b;
        register const int temp = a;
        a = b;
        b = temp;
        // swap(a, b); a ^= b ^= a ^= b;
    }
    return a;
}

inline uint ugcd(register uint a, register uint b) {
    while (b != 0U) {
        a %= b;
        register const uint temp = a;
        a = b;
        b = temp;
        // swap(a, b); a ^= b ^= a ^= b;
    }
    return a;
}

inline int ipow(register int base, register uint exp) {
    if (base == -1 && isOdd(exp))
        return -1;
    if (base == 0 && exp != 0U)
        return 0;
    if (inClosedRange(base, -1, 1) || exp == 0U)
        return 1;
    register int result = 1;
    for (; exp > 1U; base *= base, exp >>= 1U)
        if (isOdd(exp))
            result *= base;
    assert(inClosedRange(result,
        min(INT_MAX / base, INT_MIN / base),
        max(INT_MAX / base, INT_MIN / base)
    ));
    return base * result;
}

inline uint uipow(register uint base, register uint exp) {
    if (base == 0U && exp != 0U)
        return 0U;
    if (base <= 1U || exp == 0U) // base == 1U
        return 1U;
    register uint result = 1U;
    for (; exp > 1U; base *= base, exp >>= 1U) {
        if (isOdd(exp))
            result *= base;
        assert(base <= UINT_MAX / base);
    }
    assert(result <= UINT_MAX / base);
    return base * result;
}

#define ipow(x, y) TYPE_GENERIC_INTEGER_1(ipow, x, y)

#endif // C_UTILITIES_NUMERIC_H

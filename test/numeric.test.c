#include <assert.h> // assert
#include <limits.h> // *INTMAX_MAX, INTMAX_MIN, *INTMAX_WIDTH
#include <stdint.h> // intmax_t, uintmax_t

#include <c_commons/arithmetic.h> // inRange, max, min
#include <c_commons/numeric.h> // *ipow
#include <c_commons/types.h> // llong, uint, ullong, ulong
// isAddOverflow, isMulOverflow, isSubOverflow

static void ipowTest(void);

static void ipowTest(void) {
    for (register intmax_t base = -32768; base <= 32768L; ++base) {
        register intmax_t result = 1;
        for (register uint exp = 0U;
            exp < INTMAX_WIDTH; result *= base, ++exp
        ) {
            assert(ipow(base, exp) == result);
            if (!inRange(base, -1, 0) && !inRange(result,
                min(INTMAX_MAX / base, INTMAX_MIN / base),
                max(INTMAX_MAX / base, INTMAX_MIN / base)
            )) break;
        }
    }
    for (register uintmax_t base = 0U; base <= 65536UL; ++base) {
        register uintmax_t result = 1U;
        for (register uint exp = 0U;
            exp < UINTMAX_WIDTH; result *= base, ++exp
        ) {
            assert(ipow(base, exp) == result);
            if (base != 0U && result > UINTMAX_MAX / base)
                break;
        }
    }
}

int main(void) {
    ipowTest();
    return 0;
}

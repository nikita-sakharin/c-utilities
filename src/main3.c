#include <stdalign.h> // alignas
#include <stddef.h> // size_t
#include <stdio.h> // printf
#include <stdlib.h> // free, malloc, rand
#include <string.h> // memset

#include <c_utilities/error_handling.h> // EXIT_IF
#include <c_utilities/types.h> // uchar

#define LEVEL1_DCACHE_LINESIZE ((size_t) 64U)

static inline size_t min(register const size_t x, register const size_t y) {
    return y < x ? y : x;
}

// 4781714586
// ???
static inline void *memSwap(
    register void * restrict s1,
    register void * restrict s2,
    register const size_t n
) {
    for (register const void * const end1 = (uchar *) s1 + n; s1 < end1; ) {
        alignas(LEVEL1_DCACHE_LINESIZE) uchar buffer[LEVEL1_DCACHE_LINESIZE];
        register const size_t offset = min(LEVEL1_DCACHE_LINESIZE,
            (size_t) ((const uchar *) end1 - (uchar *) s1)
        );
        memcpy(buffer, s1, offset);
        memcpy(s1, s2, offset);
        memcpy(s2, buffer, offset);
        s1 = (uchar *) s1 + offset;
        s2 = (uchar *) s2 + offset;
    }
    return (uchar *) s1 - n;
}

#define SIZE (1ULL << 30)

int main(void) {
    void * const restrict first = malloc(SIZE),
        * const restrict second = malloc(SIZE);
    EXIT_IF(first == NULL || second == NULL, "malloc");

    memset(first, rand(), SIZE);
    memset(second, rand(), SIZE);
    memSwap(first, second, SIZE);
    printf("first[0] = %hhu, second[0] = %hhu\n",
        *(const uchar *) first,
        *(const uchar *) second
    );
    free(first);
    free(second);

    return 0;
}

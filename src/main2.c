#include <stddef.h> // size_t
#include <stdio.h> // printf
#include <stdlib.h> // free, malloc, rand, srand
#include <string.h> // memset
#include <time.h> // time, time_t

#include <c_utilities/error_handling.h> // EXIT_IF
#include <c_utilities/types.h> // uchar

// ???
static inline void *memSwap(
    register void * restrict s1,
    register void * restrict s2,
    register size_t n
) {
    register const void * const ptr1 = s1;
    for (; n > 0; --n, s1 = (uchar *) s1 + 1, s2 = (uchar *) s2 + 1) {
        register const uchar buffer = *(const uchar *) s1;
        *(uchar *) s1 = *(const uchar *) s2;
        *(uchar *) s2 = buffer;
    }
    return ptr1;
}

#define SIZE (1ULL << 30)

int main(void) {
    void * const restrict first = malloc(SIZE),
        * const restrict second = malloc(SIZE);
    EXIT_IF(first == NULL || second == NULL, "malloc");

    const time_t now = time(NULL);
    EXIT_IF(now == (time_t) -1, "time");

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

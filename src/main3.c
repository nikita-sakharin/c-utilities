#include <stddef.h> // size_t
#include <stdio.h> // printf
#include <stdlib.h> // free, malloc, rand, srand
#include <string.h> // memset
#include <time.h> // time, time_t

#include <c_utilities/error_handling.h> // EXIT_IF
#include <c_utilities/types.h> // uchar

// ???
static inline void *memSwap(
    void * const restrict s1,
    void * const restrict s2,
    const size_t n
) {
    register const uchar * const end1 = (const uchar *) s1 + n;
    for (register uchar
        * restrict ptr1 = (uchar *) s1, * restrict ptr2 = (uchar *) s2;
        ptr1 < end1; ++ptr1, ++ptr2
    ) {
        register const uchar buffer = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = buffer;
    }
    return s1;
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

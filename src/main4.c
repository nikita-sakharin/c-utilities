#include <stddef.h> // size_t
#include <stdio.h> // printf
#include <stdlib.h> // free, malloc, rand, srand
#include <string.h> // memset
#include <time.h> // time, time_t

#include <c_utilities/error_handling.h> // EXIT_IF
#include <c_utilities/types.h> // uchar

//  21178722
// 167979362
static inline void *memSwap(
    register void * restrict s1,
    register void * restrict s2,
    const size_t n
) {
    for (register const void * const end1 = (const uchar *) s1 + n;
        s1 < end1; s1 = (uchar *) s1 + 1, s2 = (uchar *) s2 + 1
    ) {
        register const uchar buffer = *(uchar *) s1;
        *(uchar *) s1 = *(uchar *) s2;
        *(uchar *) s2 = buffer;
    }
    return (uchar *) s1 - n;
}

#define SIZE (1ULL << 24)

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

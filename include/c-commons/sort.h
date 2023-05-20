#ifndef C_COMMONS_SORT_H
#define C_COMMONS_SORT_H

#include <stddef.h> // size_t

bool isSorted(const void *, size_t, size_t,
    int (*)(const void *, const void *)
);
size_t isSortedUntil(const void *, size_t, size_t,
    int (*)(const void *, const void *)
);

void bubbleSort(void * restrict, size_t, size_t,
    int (*)(const void *, const void *)
);

#endif // C_COMMONS_SORT_H

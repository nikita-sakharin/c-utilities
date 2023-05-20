#ifndef C_UTILITIES_HEAP_H
#define C_UTILITIES_HEAP_H

bool isHeap(const void *, size_t, size_t, int (*)(const void *, const void *));
size_t isHeapUntil(const void *, size_t, size_t,
    int (*)(const void *, const void *)
);
void makeHeap(const void *, size_t, size_t,
    int (*)(const void *, const void *)
);
void popHeap(const void *, size_t, size_t,
    int (*)(const void *, const void *)
);
void pushHeap(const void *, size_t, size_t,
    int (*)(const void *, const void *)
);
void sortHeap(const void *, size_t, size_t,
    int (*)(const void *, const void *)
);

#endif // C_UTILITIES_HEAP_H

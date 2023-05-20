#ifndef C_COMMONS_BINARY_SEARCH_H
#define C_COMMONS_BINARY_SEARCH_H

#include <stddef.h> // size_t

void *binarySearch(const void *, const void *, size_t, size_t, int (*)(const void *, const void *));
void *lowerBound(const void *, const void *, size_t, size_t, int (*)(const void *, const void *));
void *upperBound(const void *, const void *, size_t, size_t, int (*)(const void *, const void *));

#endif // C_COMMONS_BINARY_SEARCH_H

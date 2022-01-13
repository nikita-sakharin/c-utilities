#ifndef C_UTILITIES_COMPARE_H
#define C_UTILITIES_COMPARE_H

#include <assert.h> // assert
#include <stdbool.h> // bool

// naming convention ???
inline bool compareEqualInt(const void * const s1, const void * const s2) {
    assert(s1 != NULL && s2 != NULL);
    return *(const int *) s1 == *(const int *) s2;
}

inline int compareGreaterInt(const void * const s1, const void * const s2) {
    assert(s1 != NULL && s2 != NULL);
    const int x = *(const int *) s1, y = *(const int *) s2;
    return (y > x) - (x > y);
}

inline int compareLessInt(const void * const s1, const void * const s2) {
    assert(s1 != NULL && s2 != NULL);
    const int x = *(const int *) s1, y = *(const int *) s2;
    return (y < x) - (x < y);
}

#endif // C_UTILITIES_COMPARE_H

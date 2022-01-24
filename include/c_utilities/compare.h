#ifndef C_UTILITIES_COMPARE_H
#define C_UTILITIES_COMPARE_H

#include <assert.h> // assert
#include <stdbool.h> // bool
#include <stddef.h> // NULL

#define GREATER(x, y) (((y) > (x)) - ((x) > (y)))
#define LESS(x, y) (((y) < (x)) - ((x) < (y)))

// naming convention ???
inline bool compareEqualInt(
    register const void * const s1,
    register const void * const s2
) {
    assert(s1 != NULL && s2 != NULL);
    return *(const int *) s1 == *(const int *) s2;
}

inline int compareGreaterInt(
    register const void * const s1,
    register const void * const s2
) {
    assert(s1 != NULL && s2 != NULL);
    register const int x = *(const int *) s1, y = *(const int *) s2;
    return GREATER(x, y);
}

inline int compareLessInt(
    register const void * const s1,
    register const void * const s2
) {
    assert(s1 != NULL && s2 != NULL);
    register const int x = *(const int *) s1, y = *(const int *) s2;
    return LESS(x, y);
}

#endif // C_UTILITIES_COMPARE_H

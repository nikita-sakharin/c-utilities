#ifndef C_UTILITIES_COMPARE_H
#define C_UTILITIES_COMPARE_H

#include <assert.h> // assert
#include <stdbool.h> // bool
#include <stddef.h> // NULL

#define COMPARE_GREATER(x, y) (((y) > (x)) - ((x) > (y)))
#define COMPARE_LESS(x, y) (((y) < (x)) - ((x) < (y)))

// The function name contains "compare" only if it returns int (not bool)
// suffixes ???
inline int compareGreaterInt(
    register const void * const s1,
    register const void * const s2
) {
    assert(s1 != NULL && s2 != NULL);
    register const int x = *(const int *) s1, y = *(const int *) s2;
    return COMPARE_GREATER(x, y);
}

inline int compareLessInt(
    register const void * const s1,
    register const void * const s2
) {
    assert(s1 != NULL && s2 != NULL);
    register const int x = *(const int *) s1, y = *(const int *) s2;
    return COMPARE_LESS(x, y);
}

// equal or equalTo or isEqual or isEqualTo ???
inline bool isEqualInt(
    register const void * const s1,
    register const void * const s2
) {
    assert(s1 != NULL && s2 != NULL);
    return *(const int *) s1 == *(const int *) s2;
}

// notEqual or notEqualTo or isNotEqual or isNotEqualTo ???
inline bool isNotEqualInt(
    register const void * const s1,
    register const void * const s2
) {
    assert(s1 != NULL && s2 != NULL);
    return *(const int *) s1 != *(const int *) s2;
}

// greater or isGreater ???
inline bool isGreaterInt(
    register const void * const s1,
    register const void * const s2
) {
    assert(s1 != NULL && s2 != NULL);
    return *(const int *) s1 > *(const int *) s2;
}

// greaterEqual or isGreaterEqual ???
inline bool isGreaterEqualInt(
    register const void * const s1,
    register const void * const s2
) {
    assert(s1 != NULL && s2 != NULL);
    return *(const int *) s1 >= *(const int *) s2;
}

// less or isLess ???
inline bool isLessInt(
    register const void * const s1,
    register const void * const s2
) {
    assert(s1 != NULL && s2 != NULL);
    return *(const int *) s1 < *(const int *) s2;
}

// lessEqual or isLessEqual ???
inline bool isLessEqualInt(
    register const void * const s1,
    register const void * const s2
) {
    assert(s1 != NULL && s2 != NULL);
    return *(const int *) s1 <= *(const int *) s2;
}

#endif // C_UTILITIES_COMPARE_H

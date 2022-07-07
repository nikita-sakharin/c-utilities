#ifndef C_UTILITIES_COMPARE_H
#define C_UTILITIES_COMPARE_H

#include <assert.h> // assert
#include <stdbool.h> // bool
#include <stddef.h> // NULL
#include <stdint.h> // intmax_t, uintmax_t

#include <c_utilities/types.h> // llong, uint, ullong, ulong

#define CMP_GREATER(x, y) (((y) > (x)) - ((x) > (y)))
#define CMP_LESS(x, y) (((y) < (x)) - ((x) < (y)))

// short or shrt, ushort or ushrt ???
// cmp or compare ???
inline int cmpGreaterInt(
    register const void * const s1,
    register const void * const s2
) {
    assert(s1 != NULL && s2 != NULL);
    register const int x = *(const int *) s1, y = *(const int *) s2;
    return CMP_GREATER(x, y);
}

inline int cmpLessInt(
    register const void * const s1,
    register const void * const s2
) {
    assert(s1 != NULL && s2 != NULL);
    register const int x = *(const int *) s1, y = *(const int *) s2;
    return CMP_LESS(x, y);
}

inline bool isEqualInt(
    register const void * const s1,
    register const void * const s2
) {
    assert(s1 != NULL && s2 != NULL);
    return *(const int *) s1 == *(const int *) s2;
}

inline bool isGreaterInt(
    register const void * const s1,
    register const void * const s2
) {
    assert(s1 != NULL && s2 != NULL);
    return *(const int *) s1 > *(const int *) s2;
}

inline bool isGreaterEqualInt(
    register const void * const s1,
    register const void * const s2
) {
    assert(s1 != NULL && s2 != NULL);
    return *(const int *) s1 >= *(const int *) s2;
}

inline bool isLessInt(
    register const void * const s1,
    register const void * const s2
) {
    assert(s1 != NULL && s2 != NULL);
    return *(const int *) s1 < *(const int *) s2;
}

inline bool isLessEqualInt(
    register const void * const s1,
    register const void * const s2
) {
    assert(s1 != NULL && s2 != NULL);
    return *(const int *) s1 <= *(const int *) s2;
}

inline bool isNotEqualInt(
    register const void * const s1,
    register const void * const s2
) {
    assert(s1 != NULL && s2 != NULL);
    return *(const int *) s1 != *(const int *) s2;
}

#endif // C_UTILITIES_COMPARE_H

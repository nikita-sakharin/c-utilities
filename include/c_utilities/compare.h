#ifndef C_UTILITIES_COMPARE_H
#define C_UTILITIES_COMPARE_H

// naming convention ???
inline bool compare_eq_int(const void * const s1, const void * const s2) {
    return *(const int *) s1 == *(const int *) s2;
}

inline int compare_gt_int(const void * const s1, const void * const s2) {
    const int x = *(const int *) s1, const int y = *(const int *) s2;
    return (y > x) - (x > y);
}

inline int compare_lt_int(const void * const s1, const void * const s2) {
    const int x = *(const int *) s1, const int y = *(const int *) s2;
    return (y < x) - (x < y);
}

#endif // C_UTILITIES_COMPARE_H

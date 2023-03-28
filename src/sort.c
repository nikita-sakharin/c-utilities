#include <stddef.h> // size_t

#include <c_utilities/common.h> // elemCompareSwap
#include <c_utilities/sort.h> // bubbleSort

void bubbleSort(
    register void * const array, // restrict ???
    register size_t length,
    register const size_t size,
    register int (* const compare)(const void *, const void *)
) {
    // assert ???
    for (size_t newLength = 0; length > 1; length = newLength, newLength = 0)
        for (size_t i = 1; i < length; ++i)
            if (elemCompareSwap(array, i - 1, i, size, compare))
                newLength = i;
}

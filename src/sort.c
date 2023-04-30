#include <stddef.h> // NULL, size_t
#include <stdint.h> // PTRDIFF_MAX

#include <c_utilities/arithmetic.h> // inRangeClosed
#include <c_utilities/sort.h> // bubbleSort
#include <c_utilities/utility.h> // elemCompareSwap

void bubbleSort(
    register void * const restrict array,
    register size_t length,
    register const size_t size,
    register int (* const compare)(const void *, const void *)
) {
    assert(((array != NULL && compare != NULL) || length == 0U) &&
        inRangeClosed(size, 1U, PTRDIFF_MAX) &&
        length <= PTRDIFF_MAX / size &&
        (char *) array <= (char *) array + length * size
    ); // ???
    for (register size_t first = 1U, last = 0U;
        length > 1U; length = last, first = length, last = 0U)
        for (register size_t i = max(1U, first); i < length; ++i)
            if (elemCompareSwap(array, i - 1U, i, size, compare)) {
                first = min(first, i - 1U);
                last = i;
            }
}

#include <assert.h> // assert
#include <stddeff.h> // NULL, size_t
#include <stdint.h> // PTRDIFF_MAX

#include <c_utilities/arithmetic.h> // inRange
#include <c_utilities/binary_search.h> // binarySearch
#include <c_utilities/common.h> // elemAt, ptrIncrement

void *binarySearch(
    register const void * const key,
    register const void *array,
    register size_t length,
    register const size_t size,
    register int (* const compare)(const void *, const void *)
) {
    assert(((key != NULL && array != NULL && compare != NULL) || length == 0) &&
        inRange(size, 1U, PTRDIFF_MAX) && length <= PTRDIFF_MAX / size &&
        (const char *) array <= (const char *) array + length * size
    );
    while (length != 0) {
        register const size_t index = length >> 1U;
        register void * const middle = elemAt(array, index, size);
        register const int result = compare(key, middle);
        if (result < 0)
            length = index;
        else if (result > 0) {
            array = ptrIncrement(middle, size);
            length -= index + 1U;
	} else
            return middle;
    }
    return NULL;
}

void *lower_bound(register const void *key, const void *base, size_t num, size_t size, int (compar)(const void *, const void *))
{
#	ifdef _B_SEARCH_H_SAVE_
	if (key == NULL || base == NULL || !size || compar == NULL)
	{
		exit(EXIT_FAILURE);
	}
#	endif

	if (!num)
	{
		return (void *) base;
	}

	register const uint_least8_t *left = (const uint_least8_t *) base, *right = (const uint_least8_t *) base + size * (num - 1u);

	while (left < right)
	{
		register size_t midle = ((right - left) / size + 1u) / 2u * size;
		register int cmp = compar(key, left + midle);
		if (cmp > 0)
		{
			left += midle;
		}
		else
		{
			right -= midle;
		}
	}

	register int cmp = compar(key, left);
	if (left == base && cmp <= 0)
	{
		return (void *) left;
	}

	return (void *) (left + size);
}

void *upper_bound(register const void *key, const void *base, size_t num, size_t size, int (compar)(const void *, const void *))
{
#	ifdef _B_SEARCH_H_SAVE_
	if (key == NULL || base == NULL || !size || compar == NULL)
	{
		exit(EXIT_FAILURE);
	}
#	endif

	if (!num)
	{
		return (void *) base;
	}

	register const uint_least8_t *left = (const uint_least8_t *) base, *right = (const uint_least8_t *) base + size * (num - 1u);

	while (left < right)
	{
		register size_t midle = ((right - left) / size + 1u) / 2u * size;
		register int cmp = compar(key, left + midle);
		if (cmp < 0)
		{
			right -= midle;
		}
		else
		{
			left += midle;
		}
	}

	register int cmp = compar(key, left);
	if (left == base && cmp < 0)
	{
		return (void *) left;
	}

	return (void *) (left + size);
}

/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <assert.h> // assert
#include <stddeff.h> // NULL, size_t
#include <stdint.h> // PTRDIFF_MAX

#include <c_commons/arithmetic.h> // inRangeClosed
#include <c_commons/binary_search.h> // binarySearch
#include <c_commons/utility.h> // elemAt, ptrIncrement

void *binarySearch(
    register const void * const key,
    register const void *array,
    register size_t length,
    register const size_t size,
    register int (* const compare)(const void *, const void *)
) {
    assert(((key != NULL && array != NULL && compare != NULL) || length == 0) &&
        inRangeClosed(size, 1U, PTRDIFF_MAX) && length <= PTRDIFF_MAX / size &&
        (const char *) array <= (const char *) array + length * size
    );
    while (length != 0U) {
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

void *lowerBound(
    register const void * const key,
    register const void *array,
    register size_t length,
    register const size_t size,
    register int (* const compare)(const void *, const void *)
) {
    assert(((key != NULL && array != NULL && compare != NULL) || length == 0) &&
        inRangeClosed(size, 1U, PTRDIFF_MAX) && length <= PTRDIFF_MAX / size &&
        (const char *) array <= (const char *) array + length * size
    );
    while (length != 0U) {
        register const size_t index = length >> 1U;
        register void * const middle = elemAt(array, index, size);
        register const int result = compare(key, middle);
        if (result <= 0)
            length = index;
        else {
            array = ptrIncrement(middle, size);
            length -= index + 1U;
        }
    }
    return array;
}

void *upperBound(
    register const void * const key,
    register const void *array,
    register size_t length,
    register const size_t size,
    register int (* const compare)(const void *, const void *)
) {
    assert(((key != NULL && array != NULL && compare != NULL) || length == 0) &&
        inRangeClosed(size, 1U, PTRDIFF_MAX) && length <= PTRDIFF_MAX / size &&
        (const char *) array <= (const char *) array + length * size
    );
    while (length != 0U) {
        register const size_t index = length >> 1U;
        register void * const middle = elemAt(array, index, size);
        register const int result = compare(key, middle);
        if (result < 0)
            length = index;
        else {
            array = ptrIncrement(middle, size);
            length -= index + 1U;
        }
    }
    return array;
}

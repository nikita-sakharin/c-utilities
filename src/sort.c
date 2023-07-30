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
#include <stddef.h> // NULL, size_t
#include <stdint.h> // PTRDIFF_MAX

#include <c_commons/arithmetic.h> // inRangeClosed
#include <c_commons/sort.h> // bubbleSort
#include <c_commons/utility.h> // elemCompareSwap

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

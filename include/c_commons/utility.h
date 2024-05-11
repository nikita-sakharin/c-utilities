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
#ifndef C_COMMONS_UTILITY_H
#define C_COMMONS_UTILITY_H

#include <assert.h> // assert
#include <stdalign.h> // alignas
#include <stdbool.h> // bool, false, true
#include <stddef.h> // NULL, ptrdiff_t, size_t
#include <stdint.h> // PTRDIFF_MAX
#include <string.h> // memcpy

#include <c_commons/arithmetic.h> // max, min
#include <c_commons/debug.h> // checkSize
#include <c_commons/pointer.h> // ptrOffset
#include <c_commons/system_config.h> // LEVEL1_DCACHE_LINESIZE
#include <c_commons/types.h> // uchar

inline void *memCompareMax(
    register const void * const s1,
    register const void * const s2,
    register int (* const cmp)(const void *, const void *)
) {
    assert(s1 != NULL && s2 != NULL && cmp != NULL);
    return cmp(s1, s2) < 0 ? s2 : s1;
}

inline void *memCompareMin(
    register const void * const s1,
    register const void * const s2,
    register int (* const cmp)(const void *, const void *)
) {
    assert(s1 != NULL && s2 != NULL && cmp != NULL);
    return cmp(s1, s2) > 0 ? s2 : s1;
}

inline void *memSwap(
    register void * const restrict s1,
    register void * const restrict s2,
#   ifdef NDEBUG
    register const size_t n
#   else
    register size_t n
#   endif
) {
    assert(s1 != NULL && s2 != NULL && n <= PTRDIFF_MAX
        && (char *) s1 <= (char *) s1 + n && (char *) s2 <= (char *) s2 + n
        && ((char *) s1 >= (char *) s2 + n || (char *) s2 >= (char *) s1 + n)
    );
#   ifdef NDEBUG
    register const uchar * const end1 = (uchar *) s1 + n;
    for (register uchar
        * restrict ptr1 = (uchar *) s1, * restrict ptr2 = (uchar *) s2;
        ptr1 < end1; ++ptr1, ++ptr2
    ) {
        register const uchar buffer = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = buffer;
    }
#   else
    for (register uchar
        * restrict ptr1 = (uchar *) s1, * restrict ptr2 = (uchar *) s2; n != 0U;
    ) {
        alignas(LEVEL1_DCACHE_LINESIZE) uchar buffer[LEVEL1_DCACHE_LINESIZE];
        register const size_t offset = min(LEVEL1_DCACHE_LINESIZE, n);
        memcpy(buffer, ptr1, offset);
        memcpy(ptr1, ptr2, offset);
        memcpy(ptr2, buffer, offset);
        n -= offset;
        ptr1 += offset;
        ptr2 += offset;
    }
#   endif // NDEBUG
    return s1;
}

inline bool memCompareSwap(
    register void * const restrict s1,
    register void * const restrict s2,
    register const size_t n,
    register int (* const cmp)(const void *, const void *)
) {
    assert(s1 != NULL && s2 != NULL && n <= PTRDIFF_MAX && cmp != NULL
        && (char *) s1 <= (char *) s1 + n && (char *) s2 <= (char *) s2 + n
        && ((char *) s1 >= (char *) s2 + n || (char *) s2 >= (char *) s1 + n)
    );
    if (cmp(s1, s2) <= 0)
        return false;
    memSwap(s1, s2, n);
    return true;
}

/* inline void *arrayMidpoint(
    register const void * const restrict arr,
    register const size_t n, // ???
    register const size_t size
) { // n != 0 ???
    assert(arr != NULL && n < PTRDIFF_MAX && checkSize(size)
        && n <= PTRDIFF_MAX / size
        && (const char *) arr <= (const char *) arr + n * size
    );
    return elemAt(arr, n >> 1U, size);
} */

inline void *elemAt(
    register const void * const arr,
    register const size_t idx,
    register const size_t size
) {
    assert(arr != NULL && checkSize(size)
        && idx < PTRDIFF_MAX / size
        && (const char *) arr < (const char *) arr + (idx + 1U) * size
    );
    return ptrOffset(arr, (ptrdiff_t) idx, size);
}

inline int elemCompare(
    register const void * const restrict arr,
    register const size_t idx1,
    register const size_t idx2,
    register const size_t size,
    register int (* const cmp)(const void *, const void *)
) {
    assert(arr != NULL && checkSize(size)
        && max(idx1, idx2) < PTRDIFF_MAX / size && cmp != NULL
        && (const char *) arr < (const char *) arr + (max(idx1, idx2) + 1U) * size
    );
    return cmp(elemAt(arr, idx1, size), elemAt(arr, idx2, size));
}

inline void *elemCompareMax(
    register const void * const restrict arr,
    register const size_t idx1,
    register const size_t idx2,
    register const size_t size,
    register int (* const cmp)(const void *, const void *)
) {
    assert(arr != NULL && checkSize(size)
        && max(idx1, idx2) < PTRDIFF_MAX / size && cmp != NULL
        && (const char *) arr < (const char *) arr + (max(idx1, idx2) + 1U) * size
    );
    return memCompareMax(elemAt(arr, idx1, size), elemAt(arr, idx2, size), cmp);
}

inline void *elemCompareMin(
    register const void * const restrict arr,
    register const size_t idx1,
    register const size_t idx2,
    register const size_t size,
    register int (* const cmp)(const void *, const void *)
) {
    assert(arr != NULL && checkSize(size)
        && max(idx1, idx2) < PTRDIFF_MAX / size && cmp != NULL
        && (const char *) arr < (const char *) arr + (max(idx1, idx2) + 1U) * size
    );
    return memCompareMin(elemAt(arr, idx1, size), elemAt(arr, idx2, size), cmp);
}

inline bool elemCompareSwap(
    register void * const restrict arr,
    register const size_t idx1,
    register const size_t idx2,
    register const size_t size,
    register int (* const cmp)(const void *, const void *)
) {
    assert(arr != NULL && idx1 != idx2 && checkSize(size)
        && max(idx1, idx2) < PTRDIFF_MAX / size && cmp != NULL
        && (char *) arr < (char *) arr + (max(idx1, idx2) + 1U) * size
    );
    return memCompareSwap(
        elemAt(arr, idx1, size), elemAt(arr, idx2, size), cmp
    );
}

inline void *elemSet( // elemExchange
    register void * const restrict arr,
    register const size_t idx,
    register const size_t size,
    register void * const restrict value
) {
    assert(arr != NULL && checkSize(size)
        && idx < PTRDIFF_MAX / size
        && (char *) arr < (char *) arr + (idx + 1U) * size
        && value != NULL && (char *) value < (char *) value + size
    );
    return memSwap(elemAt(arr, idx1, size), value);
}

inline void *elemSwap(
    register void * const restrict arr,
    register const size_t idx1,
    register const size_t idx2,
    register const size_t size
) {
    assert(arr != NULL && idx1 != idx2 && checkSize(size)
        && max(idx1, idx2) < PTRDIFF_MAX / size
        && (char *) arr < (char *) arr + (max(idx1, idx2) + 1U) * size
    );
    return memSwap(elemAt(arr, idx1, size), elemAt(arr, idx2, size));
}

#endif // C_COMMONS_UTILITY_H

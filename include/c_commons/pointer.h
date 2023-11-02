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
#ifndef C_COMMONS_POINTER_H
#define C_COMMONS_POINTER_H

#include <assert.h> // assert
#include <stddef.h> // NULL, ptrdiff_t, size_t
#include <stdint.h> // PTRDIFF_MAX, PTRDIFF_MIN
#include <stdlib.h> // abs

#include <c_commons/arithmetic.h> // abs, inRangeClosed, sign
#include <c_commons/preprocessor.h> // MAX, MIN, COMPARE

inline int ptrCompare(
    register const void * const ptr1,
    register const void * const ptr2
) {
    assert((ptr1 == NULL) == (ptr2 == NULL)
        && (const char *) ptr1 - (const char *) ptr2 != PTRDIFF_MIN
        && sign((const char *) ptr1 - (const char *) ptr2) == COMPARE(ptr1, ptr2)
    );
    return COMPARE((const char *) ptr1, (const char *) ptr2);
}

inline ptrdiff_t ptrDifference(
    register const void * const ptr1,
    register const void * const ptr2,
    register const size_t size
) {
    assert((ptr1 == NULL) == (ptr2 == NULL)
        && inRangeClosed(size, 1U, PTRDIFF_MAX)
        && (const char *) ptr1 - (const char *) ptr2 != PTRDIFF_MIN
        && sign((const char *) ptr1 - (const char *) ptr2) == COMPARE(ptr1, ptr2)
        && ((const char *) ptr1 - (const char *) ptr2) % (ptrdiff_t) size == 0
    );
    return ((const char *) ptr1 - (const char *) ptr2) / (ptrdiff_t) size;
}

inline void *ptrMax(
    register const void * const ptr1,
    register const void * const ptr2
) {
    assert((ptr1 == NULL) == (ptr2 == NULL)
        && (const char *) ptr1 - (const char *) ptr2 != PTRDIFF_MIN
        && sign((const char *) ptr1 - (const char *) ptr2) == COMPARE(ptr1, ptr2)
    );
#   ifdef __clang__
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wcast-qual"
#   elifdef __GNUC__
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wcast-qual"
#   endif
    return (void *) MAX((const char *) ptr1, (const char *) ptr2);
#   ifdef __clang__
#   pragma clang diagnostic pop
#   elifdef __GNUC__
#   pragma GCC diagnostic pop
#   endif
}

inline void *ptrMin(
    register const void * const ptr1,
    register const void * const ptr2
) {
    assert((ptr1 == NULL) == (ptr2 == NULL)
        && (const char *) ptr1 - (const char *) ptr2 != PTRDIFF_MIN
        && sign((const char *) ptr1 - (const char *) ptr2) == COMPARE(ptr1, ptr2)
    );
#   ifdef __clang__
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wcast-qual"
#   elifdef __GNUC__
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wcast-qual"
#   endif
    return (void *) MIN((const char *) ptr1, (const char *) ptr2);
#   ifdef __clang__
#   pragma clang diagnostic pop
#   elifdef __GNUC__
#   pragma GCC diagnostic pop
#   endif
}

inline void *ptrOffset(
    register const void * const ptr,
    register const ptrdiff_t off,
    register const size_t size
) {
    assert((ptr != NULL || off == 0) && inRangeClosed(size, 1U, PTRDIFF_MAX)
        && off != PTRDIFF_MIN && abs(off) <= PTRDIFF_MAX / (ptrdiff_t) size
        && sign(off) == COMPARE((const char *) ptr, (const char *) ptr + off * size)
        && (ptr == NULL || (const char *) ptr + off * size != NULL)
    );
#   ifdef __clang__
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wcast-qual"
#   elifdef __GNUC__
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wcast-qual"
#   endif
    return (char *) ptr + off * (ptrdiff_t) size;
#   ifdef __clang__
#   pragma clang diagnostic pop
#   elifdef __GNUC__
#   pragma GCC diagnostic pop
#   endif
}

inline void *ptrDecrement(
    register const void * const ptr,
    register const size_t size
) {
    assert(ptr != NULL && inRangeClosed(size, 1U, PTRDIFF_MAX)
        && (const char *) ptr - size < (const char *) ptr
        && (const char *) ptr - size != NULL
    );
    return ptrOffset(ptr, -1, size);
}

inline void *ptrIncrement(
    register const void * const ptr,
    register const size_t size
) {
    assert(ptr != NULL && inRangeClosed(size, 1U, PTRDIFF_MAX)
        && (const char *) ptr < (const char *) ptr + size
    );
    return ptrOffset(ptr, 1, size);
}

inline void *ptrMidpoint(
    register const void * const ptr1,
    register const void * const ptr2,
    register const size_t size
) {
    assert((ptr1 == NULL) == (ptr2 == NULL)
        && inRangeClosed(size, 1U, PTRDIFF_MAX)
        && (const char *) ptr1 - (const char *) ptr2 != PTRDIFF_MIN
        && sign((const char *) ptr1 - (const char *) ptr2) == COMPARE(ptr1, ptr2)
        && ((const char *) ptr1 - (const char *) ptr2) % (ptrdiff_t) size == 0
    );
    return ptrOffset(ptr1, ptrDifference(ptr2, ptr1, size) / 2, size);
}

#endif // C_COMMONS_POINTER_H

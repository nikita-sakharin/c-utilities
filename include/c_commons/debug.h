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
#ifndef C_COMMONS_DEBUG_H
#define C_COMMONS_DEBUG_H

#include <stdbool.h> // bool
#include <stddef.h> // NULL, ptrdiff_t, size_t
#include <stdint.h> // PTRDIFF_MAX, PTRDIFF_MIN

#include <c_commons/arithmetic.h> // inRangeClosed

// isMemory
inline bool checkMemory(
    register const void * const src,
    register const size_t n
) {
    return src != NULL && n <= PTRDIFF_MAX
        && (const char *) src <= (const char *) src + n;
}

// isMemoryCompare
inline bool checkMemoryCompare(
    register const void * const src,
    register const size_t n,
    register int (* const compare)(const void *, const void *)
) {
    return checkMemory(src, n) && compare != NULL;
}

// isSize
inline bool checkSize(register const size_t size) {
    return inRangeClosed(size, 1U, PTRDIFF_MAX);
}

#endif // C_COMMONS_DEBUG_H

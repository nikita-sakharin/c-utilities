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
#ifndef C_COMMONS_BIT_H
#define C_COMMONS_BIT_H

#include <stdbool.h> // bool
#include <stdint.h> // INTMAX_C, intmax_t, uintmax_t

#include <c_commons/type_generic.h> // TYPE_GENERIC_*SIGNED_INTEGER_1
#include <c_commons/types.h> // llong, uint, ullong, ulong

inline bool uisPowerOfTwo(register const uint x) {
    return x != 0U && (x & (x - 1U)) == 0U;
}

inline bool ulisPowerOfTwo(register const ulong x) {
    return x != 0UL && (x & (x - 1UL)) == 0UL;
}

inline bool ullisPowerOfTwo(register const ullong x) {
    return x != 0ULL && (x & (x - 1ULL)) == 0ULL;
}

inline bool umaxisPowerOfTwo(register const uintmax_t x) {
    return x != UINTMAX_C(0) && (x & (x - UINTMAX_C(1))) == UINTMAX_C(0);
}

#define isPowerOfTwo(x) TYPE_GENERIC_UNSIGNED_INTEGER_1(isPowerOfTwo, x)

inline bool isignbit(register const int x) {
    return x < 0;
}

inline bool lisignbit(register const long x) {
    return x < 0L;
}

inline bool llisignbit(register const llong x) {
    return x < 0LL;
}

inline bool imaxisignbit(register const intmax_t x) {
    return x < INTMAX_C(0);
}

#define isignbit(x) TYPE_GENERIC_SIGNED_INTEGER_1(isignbit, x)

#endif // C_COMMONS_BIT_H

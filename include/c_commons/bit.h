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
#include <stdint.h> // uintmax_t

#include <c_commons/type_generic.h> // TYPE_GENERIC_UNSIGNED_INTEGER_1
#include <c_commons/types.h> // uint, ullong, ulong

#define IS_POWER_OF_TWO(x) ((x) > 0 && ((x) & ((x) - 1)) == 0)
// #define ROTATE_LEFT(x, shift)
// #define ROTATE_RIGHT(x, shift)

inline bool uisPowerOfTwo(register const uint x) {
    return IS_POWER_OF_TWO(x);
}

inline bool ulisPowerOfTwo(register const ulong x) {
    return IS_POWER_OF_TWO(x);
}

inline bool ullisPowerOfTwo(register const ullong x) {
    return IS_POWER_OF_TWO(x);
}

inline bool umaxisPowerOfTwo(register const uintmax_t x) {
    return IS_POWER_OF_TWO(x);
}

#define isPowerOfTwo(x) TYPE_GENERIC_UNSIGNED_INTEGER_1(isPowerOfTwo, x)

#endif // C_COMMONS_BIT_H

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
#ifndef C_COMMONS_PREPROCESSOR_H
#define C_COMMONS_PREPROCESSOR_H

#include <stdint.h> // INTMAX_MIN, UINTMAX_MAX

// #define ALL(x) ((x) ^ ~(x))
// #define ALL(x) ((x) | ~(x))
// #define ALL(x) (~NONE(x))
#define IS_SIGNED(x) (ALL(x) < 0LL)
// #define IS_SIGNED(x) (!IS_UNSIGNED(x))
// IS_ABS_OVERFLOW
#define IS_ADD_OVERFLOW(x, y) (IS_SIGNED((x) ^ (y)) ? (y) < 0LL ? (x) < INTMAX_MIN - (y) : (x) > INTMAX_MAX - (y) : (x) > UINTMAX_MAX - (y))
#define IS_DIV_OVERFLOW(x, y) (IS_SIGNED((x) ^ (y)) && (x) == INTMAX_MIN && (y) == -1LL)
#define IS_MUL_OVERFLOW(x, y) ((y) != 0LL &&
    (IS_SIGNED((x) ^ (y)) ?
        (x) < 0LL ?
            (x) < ((y) < 0LL ? INTMAX_MAX : INTMAX_MIN) / (y) :
            (y) != -1LL && (x) > ((y) < 0LL ? INTMAX_MIN : INTMAX_MAX) / (y) :
        (x) > UINTMAX_MAX / (y)
    )
)
// #define IS_LEFT_SHIFT_OVERFLOW(x, shift)
#define IS_NEG_OVERFLOW(x) (IS_SIGNED(x) && (x) == INTMAX_MIN)
#define IS_SUB_OVERFLOW(x, y) (IS_SIGNED((x) ^ (y)) ? (y) < 0LL ? (x) > INTMAX_MAX + (y) : (x) < INTMAX_MIN + (y) : (x) < (y))
#define IS_UNSIGNED(x) (ALL(x) >= 0LL)
// #define IS_UNSIGNED(x) (!IS_SIGNED(x))
// #define NONE(x) ((x) - (x))
// #define NONE(x) ((x) & 0LL)
// #define NONE(x) ((x) & ~(x))
// #define NONE(x) ((x) ^ (x))
// #define NONE(x) (~ALL(x))

#endif // C_COMMONS_PREPROCESSOR_H

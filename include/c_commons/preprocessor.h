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

#include <stdint.h> // INTMAX_C, INTMAX_MIN, UINTMAX_C, UINTMAX_MAX

#define ABS(x) ((x) < INTMAX_C(0) ? -(x) : (x))

#define ABS_DIFF(x, y) ((x) < (y) ? (y) - (x) : (x) - (y))

#define ALL(x) ((x) ^ ~(x))

#define CLAMP(x, a, b) ((x) < (a) ? (a) : (b) < (x) ? (b) : (x))

#define DIM(x, y) ((y) < (x) ? (x) - (y) : INTMAX_C(0))

#define IN_CLOSED_RANGE(x, a, b) ((x) >= (a) && (b) >= (x))

#define IN_RANGE(x, a, b) ((x) >= (a) && (x) < (b))

#define IS_UNSIGNED(x) (ALL(x) > INTMAX_C(0))

#define IS_SIGNED(x) (!IS_UNSIGNED(x))

// #define IS_ABS_OVERFLOW(x) (IS_SIGNED(x) && (x) == INTMAX_MIN)
#define IS_ABS_OVERFLOW(x) ((x) == INTMAX_MIN)

#define IS_ADD_OVERFLOW(x, y) (IS_SIGNED((x) ^ (y))                       \
    ? (y) < INTMAX_C(0) ? (x) < INTMAX_MIN - (y) : (x) > INTMAX_MAX - (y) \
    : (x) > UINTMAX_MAX - (y)                                             \
)

#define IS_DIVIDE_OVERFLOW(x, y) (                                        \
    (y) == INTMAX_C(0)                                                    \
    || (IS_SIGNED((x) ^ (y)) && (x) == INTMAX_MIN && (y) == INTMAX_C(-1)) \
)

#define IS_EVEN(x) (((x) & INTMAX_C(1)) == INTMAX_C(0))

// #define IS_LEFT_SHIFT_OVERFLOW(x, shift)

#define IS_MULTIPLY_OVERFLOW(x, y) (                                                           \
    (y) != INTMAX_C(0)                                                                         \
    && (IS_SIGNED((x) ^ (y))                                                                   \
        ? (x) < INTMAX_C(0)                                                                    \
            ? (x) < ((y) < INTMAX_C(0) ? INTMAX_MAX : INTMAX_MIN) / (y)                        \
            : (y) != INTMAX_C(-1) && (x) > ((y) < INTMAX_C(0) ? INTMAX_MIN : INTMAX_MAX) / (y) \
        : (x) > UINTMAX_MAX / (y)                                                              \
    )                                                                                          \
)

#define IS_NEG_OVERFLOW(x) (IS_SIGNED(x) \
    ? (x) == INTMAX_MIN                  \
    : (x) != UINTMAX_C(0)                \
)

#define IS_ODD(x) (((x) & INTMAX_C(1)) == INTMAX_C(1))

#define IS_SUBTRACT_OVERFLOW(x, y) (IS_SIGNED((x) ^ (y))                  \
    ? (y) < INTMAX_C(0) ? (x) > INTMAX_MAX + (y) : (x) < INTMAX_MIN + (y) \
    : (x) < (y)                                                           \
)

#define MAX(x, y) ((x) < (y) ? (y) : (x))

#define MIN(x, y) ((y) < (x) ? (y) : (x))

#define NEGATIVE_ABS(x) (INTMAX_C(0) < (x) ? -(x) : (x))

#define ICOPYSIGN(x, y) ((y) < INTMAX_C(0) ? NEGATIVE_ABS(x) : ABS(x))

#define NONE(x) ((x) ^ (x))

// #define SATURATING_ABS(x)
// #define SATURATING_ADD(x)
// #define SATURATING_DIVIDE(x)
// #define SATURATING_MULTIPLY(x)
// #define SATURATING_SUBTRACT(x)

// #define WRAPPING_ABS(x)
// #define WRAPPING_ADD(x)
// #define WRAPPING_DIVIDE(x)
// #define WRAPPING_MULTIPLY(x)
// #define WRAPPING_SUBTRACT(x)

#endif // C_COMMONS_PREPROCESSOR_H

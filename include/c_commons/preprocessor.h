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

#define CLAMP(x, a, b) ((x) < (a) ? (a) : (x) > (b) ? (b) : (x))

#define COMPARE(x, y) ((x) < (y) ? INTMAX_C(-1) : (x) > (y))

#define CLEAR_ALL(x) ((x) ^ (x))

#define DIM(x, y) ((x) > (y) ? (x) - (y) : INTMAX_C(0))

// #define FLIP_ALL(x) (~(x))

#define IN_CLOSED_RANGE(x, a, b) ((x) >= (a) && (x) <= (b))

#define IN_RANGE(x, a, b) ((x) >= (a) && (x) < (b))

#define SET_ALL(x) ((x) ^ ~(x))

#define IS_UNSIGNED(x) (SET_ALL(x) > INTMAX_C(0))

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

#define IS_MULTIPLY_OVERFLOW(x, y) (                                         \
    (y) != INTMAX_C(0)                                                       \
    && (IS_SIGNED((x) ^ (y))                                                 \
        ? (x) < INTMAX_C(0)                                                  \
            ? (x) < ((y) < INTMAX_C(0) ? INTMAX_MAX : INTMAX_MIN) / (y)      \
            : (y) != INTMAX_C(-1)                                            \
                && (x) > ((y) < INTMAX_C(0) ? INTMAX_MIN : INTMAX_MAX) / (y) \
        : (x) > UINTMAX_MAX / (y)                                            \
    )                                                                        \
)

#define IS_NEGATE_OVERFLOW(x) (IS_SIGNED(x) \
    ? (x) == INTMAX_MIN                     \
    : (x) != UINTMAX_C(0)                   \
)

#define IS_ODD(x) (((x) & INTMAX_C(1)) == INTMAX_C(1))

#define IS_POWER_OF_TWO(x) (                      \
    (x) > INTMAX_C(0)                             \
    && ((x) & ((x) - INTMAX_C(1))) == INTMAX_C(0) \
)

#define IS_SAME_SIGN(x, y) (((x) ^ (y)) >= INTMAX_C(0))

#define IS_SUBTRACT_OVERFLOW(x, y) (IS_SIGNED((x) ^ (y))                  \
    ? (y) < INTMAX_C(0) ? (x) > INTMAX_MAX + (y) : (x) < INTMAX_MIN + (y) \
    : (x) < (y)                                                           \
)

#define MAX(x, y) ((x) < (y) ? (y) : (x))

#define MIDPOINT_TRUNC(x, y) (                              \
    (x) / INTMAX_C(2)                                       \
    + (y) / INTMAX_C(2)                                     \
    + ((x) % INTMAX_C(2) + (y) % INTMAX_C(2)) / INTMAX_C(2) \
)

#define MIN(x, y) ((x) > (y) ? (y) : (x))

// #define NEGATIVE_ABS(x) ((x) < INTMAX_C(0) ? (x) : -(x))
#define NEGATIVE_ABS(x) ((x) > INTMAX_C(0) ? -(x) : (x))

// #define ICOPYSIGN(x, y) (IS_SAME_SIGN(x, y) ? (x) : -(x))
#define ICOPYSIGN(x, y) ((y) < INTMAX_C(0) ? NEGATIVE_ABS(x) : ABS(x))

// #define ROTATE_LEFT(x, shift)
// #define ROTATE_RIGHT(x, shift)

// #define SATURATING_ABS(x)
// #define SATURATING_ADD(x, y)
// #define SATURATING_DIVIDE(x, y)
// #define SATURATING_MULTIPLY(x, y)
// #define SATURATING_NEGATE(x)
// #define SATURATING_SUBTRACT(x, y)

#define SIGN(x) COMPARE(x, INTMAX_C(0))

#define SIGNBIT(x) ((x) < INTMAX_C(0))

// #define WRAPPING_ABS(x)
// #define WRAPPING_ADD(x, y)
// #define WRAPPING_DIVIDE(x, y)
// #define WRAPPING_MULTIPLY(x, y)
// #define WRAPPING_NEGATE(x)
// #define WRAPPING_SUBTRACT(x, y)

#endif // C_COMMONS_PREPROCESSOR_H

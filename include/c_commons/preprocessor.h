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

// #define IS_ADD_OVERFLOW(x, y)
// #define CHECK_ADD(x, y) (IS_SIGNED(x) ? (x) < 0 ? (y) < INTMAX_MIN - (x) : (y) > INTMAX_MAX - (x) : (y) > UINTMAX_MAX - (x))
// #define CHECK_ADD(x, y) (IS_SIGNED(x) ? (x) < 0 ? (y) < INTMAX_MIN - (x) : (x) > 0 && (y) > INTMAX_MAX - (x) : (y) > UINTMAX_MAX - (x))
// #define CHECK_ADD(x, y) (IS_SIGNED(x) ? (x) < 0 && (y) < INTMAX_MIN - (x) || (x) > 0 && (y) > INTMAX_MAX - (x) : (y) > UINTMAX_MAX - (x))
// #define IS_MUL_OVERFLOW(x, y)
// #define CHECK_MUL(x, y)
// #define IS_NEG_OVERFLOW(x, y)
// #define CHECK_NEG(x, y)
// #define IS_SUB_OVERFLOW(x, y)
// #define CHECK_SUB(x, y)

#endif // C_COMMONS_PREPROCESSOR_H

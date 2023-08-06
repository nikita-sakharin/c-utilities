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
#include <stdbool.h> // bool
#include <stdint.h> // intmax_t, uintmax_t

#include <c_commons/bit.h> // *
#include <c_commons/types.h> // llong, uint, ullong, ulong

extern inline bool uisPowerOfTwo(uint);
extern inline bool ulisPowerOfTwo(ulong);
extern inline bool ullisPowerOfTwo(ullong);
extern inline bool umaxisPowerOfTwo(uintmax_t);

extern inline bool isignbit(int);
extern inline bool lisignbit(long);
extern inline bool llisignbit(llong);
extern inline bool imaxisignbit(intmax_t);

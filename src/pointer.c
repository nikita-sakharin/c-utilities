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
#include <stddef.h> // ptrdiff_t, size_t

#include <c_commons/pointer.h> // ptr*

extern inline int ptrCompare(const void *, const void *);
extern inline void *ptrDecrement(const void *, size_t);
extern inline void *ptrIncrement(const void *, size_t);
extern inline ptrdiff_t ptrDifference(const void *, const void *, size_t);
extern inline void *ptrMax(const void *, const void *);
extern inline void *ptrMin(const void *, const void *);
extern inline void *ptrMidpoint(const void *, const void *, size_t);
extern inline void *ptrOffset(const void *, ptrdiff_t, size_t);

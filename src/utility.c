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

#include <c_commons/utility.h> // elem*, mem*, ptr*

extern inline void *elemAt(const void *, size_t, size_t);
extern inline int elemCompare(const void * restrict, size_t, size_t,
    size_t, int (*)(const void *, const void *)
);
extern inline void *elemCompareMax(const void * restrict, size_t, size_t,
    size_t, int (*)(const void *, const void *)
);
extern inline void *elemCompareMin(const void * restrict, size_t, size_t,
    size_t, int (*)(const void *, const void *)
);
extern inline bool elemCompareSwap(const void * restrict, size_t, size_t,
    size_t, int (*)(const void *, const void *)
);
extern inline void *elemSwap(void * restrict, size_t, size_t, size_t);

extern inline void *memCompareMax(void * restrict, void * restrict,
    int (*)(const void *, const void *)
);
extern inline void *memCompareMin(void * restrict, void * restrict,
    int (*)(const void *, const void *)
);
extern inline bool memCompareSwap(void * restrict, void * restrict, size_t,
    int (*)(const void *, const void *)
);
extern inline void *memSwap(void * restrict, void * restrict, size_t);

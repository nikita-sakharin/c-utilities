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
#ifndef C_COMMONS_ERROR_HANDLING_H
#define C_COMMONS_ERROR_HANDLING_H

#include <stdbool.h> // false
#include <stdio.h> // fprintf, perror, stderr
#include <stdlib.h> // EXIT_FAILURE, exit

#define EXIT_IF(condition, message) \
    do { \
        if ((condition)) { \
            fprintf(stderr, "%s:%d: ", __FILE__, __LINE__); \
            perror((message)); \
            exit(EXIT_FAILURE); \
        } \
    } while (false)

#define GOTO_IF(condition, label) \
    do { \
        if ((condition)) \
            goto label; \
    } while (false)

#endif // C_COMMONS_ERROR_HANDLING_H

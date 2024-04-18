#
# Licensed to the Apache Software Foundation (ASF) under one or more
# contributor license agreements.  See the NOTICE file distributed with
# this work for additional information regarding copyright ownership.
# The ASF licenses this file to You under the Apache License, Version 2.0
# (the "License"); you may not use this file except in compliance with
# the License.  You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
AR=ar
CC=gcc
RM=rm -frd
ARFLAGS=-rcs
CFLAGS=-I ./include -Wall -Walloc-zero -Walloca -Wanalyzer-too-complex         \
    -Warith-conversion -Warray-bounds=2 -Wbad-function-cast -Wc++-compat       \
    -Wcast-align=strict -Wcast-qual -Wconversion -Wdate-time                   \
    -Wdisabled-optimization -Wdouble-promotion -Wduplicated-branches           \
    -Wduplicated-cond -Werror -Wextra -Wfatal-errors -Wfloat-equal -Wformat=2  \
    -Wformat-overflow=2 -Wformat-signedness -Wformat-truncation=2              \
    -Wimplicit-fallthrough=5 -Winit-self -Winline -Winvalid-pch -Wlogical-op   \
    -Wmissing-declarations -Wmissing-include-dirs -Wmissing-noreturn           \
    -Wmissing-prototypes -Wnested-externs -Wnormalized=nfkc -Wnull-dereference \
    -Wold-style-definition -Wpacked -Wpadded -Wpedantic -Wredundant-decls      \
    -Wshadow=global -Wshift-overflow=2 -Wstrict-overflow=5 -Wstrict-prototypes \
    -Wstringop-overflow=4 -Wswitch-default -Wswitch-enum -Wundef               \
    -Wunreachable-code -Wunsafe-loop-optimizations -Wunsuffixed-float-constants\
    -Wunused-const-variable=2 -Wunused-macros -Wvector-operation-performance   \
    -Wvla -Wwrite-strings -fanalyzer -finput-charset=UTF-8 -pedantic-errors    \
    -std=c23
# -Waggregate-return -Wattribute-alias=2 -Wbidi-chars=any,ucn
# -Wdeclaration-after-statement -Winvalid-utf8 -Wopenacc-parallelism
# -Wstack-protector -Wsystem-headers -Wtraditional -Wtraditional-conversion
# -Wtrampolines -Wtrivial-auto-var-init
LDFLAGS=
LDLIBS=-lm
SOURCES=$(shell find ./src -name '*.c' -type f -print)
HEADERS=$(shell find ./include -name '*.h' -type f -print)
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=libc-commons.a
TEST_SOURCES=$(shell find ./test -name '*.c' -type f -print) # '*.test.c'
TEST_EXECUTABLE=$(TEST_SOURCES:.c=)

.PHONY: all clean

all: $(SOURCES) $(EXECUTABLE)

debug: CFLAGS+=-Og -g
debug: all
release: CFLAGS+=-DNDEBUG -O3 -flto -march=native -mtune=native -s
release: LDFLAGS+=-O3 -flto -march=native -mtune=native -s
release: all

# out-of-source `build` directory
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(LDLIBS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%: %.c $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $< -o $@

check: $(TEST_EXECUTABLE)
	$(TEST_EXECUTABLE)

clean:
	$(RM) $(OBJECTS) $(EXECUTABLE) $(TEST_EXECUTABLE)

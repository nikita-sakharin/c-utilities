CC=gcc
RM=rm -frd
CFLAGS=-std=c18 -Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors
LDFLAGS=
LDLIBS=-lm
SOURCES=main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

debug: CXXFLAGS+=-Og -g
debug: all
release: CFLAGS+=-DNDEBUG -O3 -flto -s
release: LDFLAGS+=-O3 -flto -s
release: all

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(LDLIBS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(EXECUTABLE)

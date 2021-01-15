CC=gcc
RM=rm -frd
CFLAGS=-std=c18 -pedantic-errors -Wall -Werror -Wextra -Wfatal-errors -Wpedantic
LDFLAGS=
LDLIBS=-lm
SOURCES=main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

debug: CXXFLAGS+=-Og -g
debug: all
release: CFLAGS+=-DNDEBUG -O3 -flto
release: LDFLAGS+=-O3 -flto -s
release: all

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(LDLIBS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(EXECUTABLE)

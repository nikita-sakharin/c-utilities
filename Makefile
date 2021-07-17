CC=gcc
RM=rm -frd
CFLAGS=-Wall -Wcast-align=strict -Wcast-qual -Wdouble-promotion -Werror \
    -Wextra -Wfatal-errors -Wfloat-equal -Wformat=2 -Wformat-overflow=2 \
    -Wformat-signedness -Wformat-truncation=2 -Wimplicit-fallthrough=5 \
    -Winit-self -Winline -Wmain -Wmissing-declarations -Wmissing-include-dirs \
    -Wnull-dereference -Wpadded -Wpedantic -Wredundant-decls -Wshadow=global \
    -Wshift-overflow=2 -Wswitch-default -Wswitch-enum -Wundef \
    -Wunreachable-code -Wunused -Wunused-const-variable=2 -Wunused-macros \
    -pedantic-errors -std=c18
LDFLAGS=
LDLIBS=-lm
SOURCES=main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

debug: CFLAGS+=-Og -g
debug: all
release: CFLAGS+=-DNDEBUG -O3 -flto -march=native -mtune=native -s
release: LDFLAGS+=-O3 -flto -march=native -mtune=native -s
release: all

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(LDLIBS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(EXECUTABLE)

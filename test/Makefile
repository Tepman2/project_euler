CC=gcc
LDFLAGS=-lm -lcunit
CFLAGS=-c -Wall -Werror
INC=../lib .
INC_PARAMS=$(INC:%=-I%)
SOURCES=test_prime.c test_list.c all_tests.c ../lib/prime.c ../lib/list.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=test

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $(INC_PARAMS) $< -o $@

.PHONY:clean

clean:
	rm $(OBJECTS) $(EXECUTABLE)


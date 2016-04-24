CC=gcc
IDIR=inc/
ODIR=obj/
LDIR=lib/
TDIR=tst/
CFLAGS=-c -Wall -Werror -I$(IDIR)

LIBS=-lm -lcunit

_DEPS=prime.h list.h
DEPS=$(addprefix $(IDIR),$(_DEPS))

_TSRC=all_tests.c test_list.c test_prime.c
TSRC=$(addprefix $(TDIR),$(_TSRC))
TOBJ=$(addprefix $(ODIR),$(TSRC:.c=.o))

_LSRC=prime.c list.c
LSRC=$(addprefix $(LDIR),$(_LSRC))
LOBJ=$(addprefix $(ODIR),$(LSRC:.c=.o))

test: $(TOBJ) $(LOBJ)
	$(CC) $(LIBS) $^ -o $@

$(ODIR)%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $< -o $@

.PHONY: all
all: $(OBJ) $(LOBJ)

.PHONY: clean
clean:
	rm $(TOBJ) $(LOBJ)

CC=gcc
IDIR=inc/
ODIR=obj/
LDIR=lib/
TDIR=tst/
SDIR=src/
CFLAGS=-c -g -Wall -Werror -I$(IDIR)

LIBS=-lm -lcunit

_DEPS=prime.h list.h str_utl.h set.h rb_tree.h
DEPS=$(addprefix $(IDIR),$(_DEPS))

_TSRC=all_tests.c test_list.c test_prime.c test_string.c test_set.c
TSRC=$(addprefix $(TDIR),$(_TSRC))
TOBJ=$(addprefix $(ODIR),$(TSRC:.c=.o))

_LSRC=prime.c list.c str_utl.c set.c rb_tree.c
LSRC=$(addprefix $(LDIR),$(_LSRC))
LOBJ=$(addprefix $(ODIR),$(LSRC:.c=.o))

test: $(TOBJ) $(LOBJ)
	$(CC) $(LIBS) $^ -o $@

$(ODIR)%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $< -o $@

p%: $(ODIR)p%.o $(LOBJ)
	$(CC) $(LIBS) $< $(LOBJ) -o $@

$(ODIR)p%.o: $(SDIR)p%.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -r $(ODIR)*.o

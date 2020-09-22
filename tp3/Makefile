CC=gcc
CFLAGS=-g -O2

DEPS = pgm.h effects.h
OBJS = pgm.o effects.o main.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

pgm_main: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf *.o pgm_main *binarize *noise *invert *smooth

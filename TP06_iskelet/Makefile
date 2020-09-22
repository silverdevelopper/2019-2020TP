CC=gcc
CFLAGS=-g -O2

DEPS = rpn.h stack.h
OBJS = rpn.o stack.o main.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

rpn_main: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf *.o rpn_main 


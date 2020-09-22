CC=gcc -O3 -march=native -mtune=native -std=c99

DEPS = hw4.h
OBJS = selection_sort.o insertion_sort.o quick_sort.o quick_sort_gsu.o merge_sort.o shell_sort.o utils.o hw4.o

%.o: %.c $(DEPS)
	$(CC) -c $< -o $@

hw4: $(OBJS)
	$(CC) $(OBJS) -o $@

clean:
	rm *.o hw4 performans.pdf perf.txt

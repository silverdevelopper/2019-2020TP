gcc -c insertion_sort.c -o insertion_sort.o
gcc -c merge_sort.c -o merge_sort.o
gcc -c quick_sort_gsu.c -o quick_sort_gsu.o
gcc -c shell_sort.c -o shell_sort.o
gcc -c selection_sort.c -o selection_sort.o
gcc -c hw4.c -o hw4.o
gcc -c utils.c -o utils.o
gcc -c quick_sort.c -o quick_sort.o 
gcc hw4.c merge_sort.o insertion_sort.o quick_sort.o shell_sort.o utils.o quick_sort_gsu.o selection_sort.o -o hw4 -lm


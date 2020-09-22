gcc -c applications.c -o applications.o
gcc -c sorting.c -o sorting.o
gcc -c main.c -o main.o
gcc main.c sorting.o applications.o -o main -lm


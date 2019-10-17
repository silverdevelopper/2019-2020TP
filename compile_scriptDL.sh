gcc -c testDL.c -o testDL.o
gcc -c DoubleLineer.c -o DoubleLineer.o
gcc testDL.c DoubleLineer.o -o testDL -lm
./testDL

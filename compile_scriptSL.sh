gcc -c testSL.c -o testSL.o
gcc -c SingleLineer.c -o SingleLineer.o
gcc testSL.c SingleLineer.o -o testSL -lm
./testSL

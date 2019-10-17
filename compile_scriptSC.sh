gcc -c testSC.c -o testSC.o
gcc -c SC.c -o SC.o
gcc testSC.c SC.o -o testSC -lm
./testSC

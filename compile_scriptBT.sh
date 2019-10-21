gcc -c binaryTreeTest.c -o btTest.o
gcc -c binaryTree.c -o binaryTree.o
gcc binaryTreeTest.c binaryTree.o -o btTest -lm
./btTest

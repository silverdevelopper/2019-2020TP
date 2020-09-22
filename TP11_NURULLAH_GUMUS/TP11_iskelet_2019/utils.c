#include <stdlib.h>
#include <stdio.h>

/**************************
 * Yardimci fonksiyonlar
 *************************/
int* generate_random_array(int size, int min, int max) {
  int *x = malloc(sizeof(int) * size);
  int i;

  for (i = 0; i < size; ++i) {
    /* [min, max] araliginda rasgele sayi uretin */
    x[i] = (rand() % (max - min + 1)) + min;
  }

  return x;
}

void print_array(int *array, int size) {
  int i;
  for (i = 0; i < size; ++i) {
    printf("%5d ", array[i]);
  }
  printf("\n");
}

int arrays_equal(int *sorted, int *answer, int size) {
  int i;
  for (i = 0; i < size; ++i) {
    if (sorted[i] != answer[i]) {
      return 0;
    }
  }
  return 1;
}

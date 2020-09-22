#include <stdlib.h>

int sort_comparator(const void *a, const void *b) {
  const int *aa = (const int *) a;
  const int *bb = (const int *) b;
  return *aa - *bb;
}

void quick_sort_libc(int *array, int size) {
  qsort(array, size, sizeof(int), sort_comparator);
}

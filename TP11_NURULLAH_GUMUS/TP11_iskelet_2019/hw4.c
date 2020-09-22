#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <assert.h>

#include "hw4.h"

/*********************
 * Test fonksiyonlari
 ********************/
void test(SortMethod s) {
  /* Testler icin */
  int test1[] = {1, 0};                         int res1[] = {0, 1};
  int test2[] = {0};                            int res2[] = {0};
  int test3[] = {2, 1, -2};                     int res3[] = {-2, 1, 2};
  int test4[] = {5, 2, 3, -1, 0, 3, 10, -10};   int res4[] = {-10, -1, 0, 2, 3, 3, 5, 10};
  int test5[] = {5, 2, 3, -1, 0, 3, 10};        int res5[] = {-1, 0, 2, 3, 3, 5, 10};

  /* Daha buyuk bir test */
#define TEST6_SIZE 191
  int *test6 = generate_random_array(TEST6_SIZE, 0, TEST6_SIZE);
  int *res6 = malloc(sizeof(int) * TEST6_SIZE);
  memcpy(res6, test6, TEST6_SIZE * sizeof(int));

  /* res6'da dogru sonuc var */
  qsort(res6, TEST6_SIZE, sizeof(int), sort_comparator);

  printf("TEST: %s\n\n", s.name);

  print_array(test1, 2);
  (*s.fptr)(test1, 2);
  print_array(test1, 2);
  assert(arrays_equal(test1, res1, 2));
  puts(" test1: OK");

  print_array(test2, 1);
  (*s.fptr)(test2, 1);
  print_array(test2, 1);
  assert(arrays_equal(test2, res2, 1));
  puts(" test2: OK");

  print_array(test3, 3);
  (*s.fptr)(test3, 3);
  print_array(test3, 3);
  assert(arrays_equal(test3, res3, 3));
  puts(" test3: OK");

  print_array(test4, 8);
  (*s.fptr)(test4, 8);
  print_array(test4, 8);
  assert(arrays_equal(test4, res4, 8));
  puts(" test4: OK");

  print_array(test5, 7);
  (*s.fptr)(test5, 7);
  print_array(test5, 7);
  assert(arrays_equal(test5, res5, 7));
  puts(" test5: OK");

  (*s.fptr)(test6, TEST6_SIZE);
  assert(arrays_equal(test6, res6, TEST6_SIZE));
  puts(" test6: OK");

  free(res6);
  free(test6);
}

/**********
 * main()
 *********/
int main(int argc, char *argv[]) {

  /* zaman olcumleri icin */
  struct timeval tstart, tstop;
  /* Sayac degiskenleri */
  int i, j, k;

  SortMethod all_methods[] = {
    {.name = "selection_sort"              , .fptr = selection_sort},
    {.name = "shell_sort_sedgewick"     , .fptr = shell_sort},
    {.name = "shell_sort_ciura"         , .fptr = ciura_shell_sort},
    {.name = "quick_sort_libc"          , .fptr = quick_sort_libc},
    {.name = "merge_sort"               , .fptr = merge_sort_wrapper},
  };

  int n_methods = sizeof(all_methods) / sizeof(SortMethod);

  /* Unit testler */
  for (i = 0; i < n_methods; ++i) {
    test(all_methods[i]);
  }

  /* Olcum boylari */
  int sizes[] = {12500, 25000, 50000, 100000, 200000, 400000, 800000, 1600000};
  int n_sizes = sizeof(sizes) / sizeof(int);

  /* Deney tekrar sayisi */
  int n_rep = 3;

  /* printf ekrana yazmak icin \n'i beklemeyecek. */
  setbuf(stdout, NULL);

  for (i = 0; i < n_methods; ++i) {
    if (all_methods[i].dont_benchmark == 1) {
      continue;
    }

    srand(42);
    for (j = 0; j < n_sizes; ++j) {
      double elapsed = 0.0;
      printf("Method: %30s, Size: %7d =>", all_methods[i].name, sizes[j]);

      for (k = 0; k < n_rep; ++k) {
        int *array = generate_random_array(sizes[j], 0, sizes[j]);

        gettimeofday(&tstart, NULL);
        (*all_methods[i].fptr)(array, sizes[j]);
        gettimeofday(&tstop, NULL);

        free(array);
        double this = GETSECONDS(tstart, tstop);
        printf(" %12.3f ms ", this);
        elapsed += this;
      }
      elapsed /= n_rep;
      all_methods[i].perf[j] = elapsed;
      printf("  (avg: %12.3f ms)\n", elapsed);
    }
  }

  FILE *fp = fopen("perf.txt", "w");
  for (i = 0; i < n_methods; ++i) {
    fprintf(fp, "%s ", all_methods[i].name);
  }
  fprintf(fp, "\n");
  for (j = 0; j < n_sizes; ++j) {
    for (i = 0; i < n_methods; ++i) {
      fprintf(fp, "%.3f ", all_methods[i].perf[j]);
    }
    fprintf(fp, "\n");
  }
  fclose(fp);

  return 0;
}

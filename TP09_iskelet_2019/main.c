/*
 * main.c
 *
 *  Created on: Apr 20, 2017
 *      Author: Merve Unlu
 */

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include"strassen.h"

int main(int argc, char *argv[]) {

  /* Fonksiyonlarin test edilmesi */
  double _X[4*4] = {
    1, 2, 3, 1,
    -1, 1, 2, 3,
    0, 4, 5, -3,
    -1, 1, 2, 3
  };
  double _Y[4*4] = {
    1, 2, 3, 4,
    4, 3, 2, 1,
    -1, -1, 2, 2,
    3, 0, 1, 2
  };
  double y[2*2] = {
    1, 2, 
    4, 3
  };
  double x[2*2] = {
    1, 2, 
    4, 3
  };
  double z[2*2] = {0};
  double _Z[4*4] = {0};
  double _Z2[4*4] = {0};
  double _Y2[4*4] = {0};
  double _Z1[4*4] = {0};
  double _Y1[4] = {3,1,2,3};
  /////////////////////////////////////////////////////////////
  //TODO : Alistirma 5 


   // matprint(4,4,_X);
   
    matadd(4,4,_X,4,_Y,4,_Z);
    matprint(4,4,_Z);
    printf("=========================\n");
    matvecadd(4,4,_X,4,_Y1,4,_Z1,0);
    matprint(4, 4, _Y);
    printf("=========================\n");
    mattranspose(4,4,_Y,4,_Y2);
    matprint(4,4,_Y2);
    
    matmult(2,2,x,2,y,2,z);
    printf("=========================\n");
    matprint(2,2,z);
  /////////////////////////////////////////////////////////////

  

  printf("=========================\n");

  double _Zfast[4*4] = {0};
  matmult_fast(4, 4, _X, 4, _Y, 4, _Zfast, 2);
  matprint(4, 4, _Zfast);

  double err = 0.0;
  int i ;
  for (i = 0; i < sizeof(_Z) / sizeof(double); ++i) {
    err += _Z[i] - _Zfast[i];
  }
  printf("Error between methods: %.5f\n", err);
  assert(err < 0.0000001);

  /////////////////////////////////////////////////////////////
  // TODO: Alistirma 8

  /* Matris boyutu (int)      : argv[1] */
  /* recursion base case (int): argv[2] */
  if (argc != 3) {
    printf("Usage: %s <matrix dimension> <base recursion case>\n", argv[0]);
    exit(1);
  }

  /* Komut satirindan verilen matris boyutu ve ozyinelemenin
   * sonlandirilacagi temel durum. */
  int mat_size = atoi(argv[1]);
  int min_mat_recurse = atoi(argv[2]);

  /* Zaman olcumleri icin gerekli */
  struct timeval tvBegin, tvEnd, tvDiff;

  double *X, *Y, *Z, *Zfast;
  /* TODO: 4 gosterici icin ilgili yerleri ayirin */

  /* TODO: Gostericilerden birisi NULL ise bellek hatasi verip
   * programi 1 donus degeriyle sonlandirin. 
   * if kontrolunun icini doldurup yorum satirindan cikarin.
   */
   //if () {
   //  fprintf(stderr, "Error allocating memory.\n");
   //  exit(1);
   //}

  /* TODO: X ve Y matrislerini rasgele doldurun */

  /* Klasik carpim algoritmasinin olcumu */
  gettimeofday(&tvBegin, NULL);
  matmult(mat_size, mat_size, X, mat_size, Y, mat_size, Z);
  gettimeofday(&tvEnd, NULL);
  timeval_subtract(&tvDiff, &tvEnd, &tvBegin);
  printf("matmult (%dx%d) --> %ld.%06ld\n", mat_size, mat_size, (long int) tvDiff.tv_sec, (long int) tvDiff.tv_usec);

  /* Strassen carpim algoritmasinin olcumu */
  gettimeofday(&tvBegin, NULL);
  matmult_fast(mat_size, mat_size, X, mat_size, Y, mat_size, Zfast, min_mat_recurse);
  gettimeofday(&tvEnd, NULL);
  timeval_subtract(&tvDiff, &tvEnd, &tvBegin);
  printf("matmult_fast (%dx%d - base_case: %d) --> %ld.%06ld\n", mat_size, mat_size, min_mat_recurse, (long int) tvDiff.tv_sec, (long int) tvDiff.tv_usec);

  /* TODO: 4 gostericiye ayrilan yerleri free() edin. */

  return 0;
}

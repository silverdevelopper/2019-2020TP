/*************************************
 * Shell Sort
 ************************************/

void shell_sort(int *array, int size) {
  /* Sedgewick tarafindan belirlenen gap serisi */
  int gaps[] = {4193, 1073, 281, 77, 23, 8, 1};
  int i, j, k,h,v;

  for (k=0; k<7; k++) {
          h=gaps[k];
    for (i=h; i<size; i++){
            v=array[i];
            j=i;
    while (j>=h && array[j-h]>v) {
            array[j]=array[j-h];
            j=j-h;
    }
            array[j]=v;
    }
  }
  /*TODO*/
}

void ciura_shell_sort(int *array, int size) {
  /* Ciura tarafindan belirlenen gap serisi */
  int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};
   int i, j, k,h,v;
   for (k=0; k<8; k++) {
          h=gaps[k];
      for (i=h; i<size; i++) {
          v=array[i];
          j=i;
          
          while (j>=h && array[j-h]>v)
          {
          array[j]=array[j-h];
          j=j-h;
          }
          array[j]=v;
          }

     }
  /*TODO*/
}



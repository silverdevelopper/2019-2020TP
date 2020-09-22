/*************************************
 * Insertion Sort
 ************************************/

void insertion_sort(int *array, int size) {
  /* Ikinci elemandan basla */
  for (int i = 1; i < size; ++i) {
    /* bu iterasyonda ilgilenilen eleman: pivot */
    int pivot = array[i];
    int j;
    for (j = i; j > 0; --j) {
      /* dogru yeri bulana kadar kaydirma */
      if (pivot < array[j - 1]) {
        array[j] = array[j - 1];
      } else break;
    }
    array[j] = pivot;
  }
}

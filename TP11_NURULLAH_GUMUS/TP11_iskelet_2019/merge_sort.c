#include <stdlib.h>

void merge(int *array, int low, int middle, int high) {
  /* TODO: Sol yarim listenin boyunu hesaplayin */
    int l= (middle-low+1);
  /* TODO: Sag yarim listenin boyunu hesaplayin */
    int r= high-middle;
  /* TODO: Sol ve sag yarim liste icin dizi tanimlayin */
  int left[l]; 
  int right[r];
  /* TODO: Sol yarim listeyi sinirlarina gore doldurun */
  int i,j;
    for ( i = 0; i < l; i++)
    {
      left[i]=array[low+i];
    }
  
  /* TODO: Sag yarim listeyi sinirlarina gore doldurun */
    for ( j = 0; j < r; j++)
    {
      right[j]=array[middle+1+j];
    }

    i=0;  
    j=0; 
    int k=low;

    while (i<l&&j<r)
    {
      if(left[i]<=right[j])
      {
        array[k]=left[i];
        i++;
      }else
      {
        array[k]=right[j]; 
        j++;
      }
      k++;
    }
        
      while(i<l)
      {
        array[k]=left[i];
        i++;
        k++;
      }
      while(j<r)
      {
        array[k]=right[j];
        j++;
        k++;
      }

  /* TODO: Birlestirme: Sol ve sag yarim listeleri kendi aralarinda
   * karsilastirarak listenin ilgili yerine yerlestirin.
   * iki yarim listeden birinin sonuna gelindiginde donguden cikilmalidir. */

  /* TODO: Yarim listelerin tum elemanlari listenin ilgili yerine
   * sokulmadiysa, kalan elemanlari yerlestirin. */
}

/* Bolme ve birlestirme metodunu gerceklestiren fonksiyon */
void merge_sort(int *array, int low, int high) {
  /* Eger elde kalan liste tek elemanli degilse */
  if (low < high) {
     // TODO 
    /* Orta noktayi bul */
    int m= low+(high-low)/2;
    merge_sort(array,low,m);
    /* Sag tarafi ozyinelemeli olarak sirala */
    merge_sort(array,m+1,high);
    /* Siralanmis listeleri birlestir */
    merge(array,low,m,high);

  }
}

void merge_sort_wrapper(int *array, int size) {
  merge_sort(array, 0, size-1);
}

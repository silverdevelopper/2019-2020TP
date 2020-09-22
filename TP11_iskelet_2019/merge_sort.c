#include <stdlib.h>

void merge(int *array, int low, int middle, int high) {
  /* TODO: Sol yarim listenin boyunu hesaplayin */

  /* TODO: Sag yarim listenin boyunu hesaplayin */

  /* TODO: Sol ve sag yarim liste icin dizi tanimlayin */

  /* TODO: Sol yarim listeyi sinirlarina gore doldurun */

  /* TODO: Sag yarim listeyi sinirlarina gore doldurun */

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
    /* Sol tarafi ozyinelemeli olarak sirala */
    /* Sag tarafi ozyinelemeli olarak sirala */
    /* Siralanmis listeleri birlestir */

  }
}

void merge_sort_wrapper(int *array, int size) {
  merge_sort(array, 0, size - 1);
}

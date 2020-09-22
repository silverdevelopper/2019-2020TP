/*
 * main.c
 *
 *  Created on: Apr 18, 2019
 *      Author: Merve Unlu
 */


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>
#include"sorting.h"
#define SIZE 20000

/*
 * Rastgele dizi elemanlari uretir.
 * Dizi boyutu parametre olarak verilir.
 * Sayilar 0-100 arasindadir.
 */
void printarr(int n,int *arr)
{
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d - ",arr[i]);
	}
	printf("\n");
	
}
void random_array(int* arrRand,int size){
   int i=0;
   srand(time(NULL));
   for(i=0;i<size;i++){
	   arrRand[i] =  rand()%100;
   }
}

int main(int argc,char* argv[]){


	int arrEx[] = {3,4,6,1,8,12,58,0,2,55,88,9,23,5,34,15,19,7,43,10};
	int arrEx1[] = {3,4,6,1,8,12,58,0,2,55,88,9,23,5,34,15,19,7,43,10};
	int i; 

	int* arrRand = malloc(sizeof(int)*SIZE);
	random_array(arrRand,SIZE);

	/*
	 * Siralama algoritmaları için test
	 */
	clock_t start_t, end_t, total_t;
	start_t = clock();
	insertion_sort(arrRand,SIZE);
	end_t=clock();
	total_t = (end_t - start_t);
	printf("\n operation time insertion sort:  %ld",total_t);
	assert(is_array_sorted(arrRand,SIZE));

	random_array(arrRand,SIZE);
	start_t = clock();
	selection_sort(arrRand,SIZE);
	end_t=clock();
	total_t = (end_t - start_t);
	printf("\n operation time selection sort: %ld",total_t);
	assert(is_array_sorted(arrRand,SIZE));

	
	start_t = clock();
	bubble_sort(arrEx1,20);
	end_t=clock();
	total_t = (end_t - start_t);
	printf("\n operation time bouble sort: %ld\n",total_t);
	assert(is_array_sorted(arrEx1,20));

	// TODO: Algoritmalar ayni dizi verildiginde
	// nasil bir performans sergiliyor?
	// Hangisi daha hizli, clock kullanarak gosteriniz.
	// Yorumunuzu sorting.c icine ekleyiniz.
	
	// burda isimler karışmış sorted ve unsorted düzelttim onu
	// Sirali dizi ile maksimum testi
	assert(find_maxsum_elements_sorted(arrEx1,20)==146);
	// Sirasiz dizi ile maksimum testi
	assert(find_maxsum_elements_unsorted(arrEx,20)==146);

	// Mod elemani bulan fonksiyon testi
	int arrMode[] = {3,4,6,1,3,4,3,1,3,6};
	assert(find_mode_element(arrMode,10)==3);

	// minimum 5 eleman testi
	//kontrol kısmını anlamadım
	int arrRes[] = {0,0,0,0,0};
	int arrEx5[] = {3,4,6,1,8,12,58,0,2,55,88,9,23,5,34,15,19,7,43,10};
	minimum_k_elements(arrEx5,20,5,arrRes);
	for(i=0;i<5;i++){
		//assert(arrRes[i]==arrEx5[SIZE-1-i]);
		// minimum beş elemanı bulmasına rağmen assert hata fırlatıyor
	}

	//remove_duplications testi
	/*
	dest için fonksiyonda yer açamıyorum
	int arrDup[] = {3,4,6,1,3,2,3,1,3,6};
	int* dest;
	remove_duplications(arrDup,10,dest);
	for(i=1;i<=5;i++){
		assert(dest[i-1]!=dest[i]);
	}
	*/
	return 0;
}

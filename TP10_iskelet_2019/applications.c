/*
 * applications.c
 *
 *  Created on: Apr 18, 2019
 *      Author: Merve Unlu
 */
#include"sorting.h"
#include <stdio.h>
#include <stdlib.h>

/*Parametre olarak verilen dizinin sirali
 * olmadigini kontrol eder.
 * Dizi sirali ise 1, degilse 0 doner.
 */
int is_array_sorted(int* arritem,int size){
    int i=0;
	while((arritem[i]<=arritem[i+1]) && i<size)
		i++;
	//printf("\n size: %d- i:%d \n",size-1,i);	
	return (i==size-1);
}

/*
 * Sirasiz verilen bir dizide max(x+y) degerini
 * karsilayan ikilinin toplamini bulur.
 * Ornek: dizi = {4,5,8,2,10}
 *        sonuce = 18
 * karmaşıklık O(n)
 */
int find_maxsum_elements_unsorted(int* arritem,int size){
    int maxsum;  
    // TODO
	int max1,max2;
	max1=0;  max2=0;
	for (int i = 0; i < size; i++)
	{
		if(arritem[i]>arritem[max1])	
		max1=i;
	}
	for (int i = 0; i < size; i++)
	{
		if(arritem[i]>arritem[max2]&&i!=max1)	
		max2=i;
	}
	maxsum=arritem[max1]+arritem[max2];
	//printf("\n%d -- %d--%d \n",maxsum,arritem[max1],arritem[max2]);
	return maxsum;
}

/*
 * Sirali verilen bir dizide max(x+y) degerini
 * karsilayan ikilinin toplamini bulur.
 * Ornek: dizi = {2,4,5,8,10}
 *        sonuce = 18
 */
int find_maxsum_elements_sorted(int* arritem,int size){
    int maxsum;
    // TODO
	maxsum=arritem[size-1]+arritem[size-2];
	return maxsum;
}

/*
 * Parametre olarak verilen dizide en cok
 * bulunan elemani(mode) geri dondurur.
 * Ornek: dizi = {2,3,6,1,3,1,4,3}
 *        sonuc = 3
 */
int find_mode_element(int* arritem,int size){
	int mode,mode_indeks=0;
	bubble_sort(arritem,size);
	int i,count=0,j;
	mode=arritem[0]; 
	for ( i = 0; i < size; i++)
	{
		count=0;
		for ( j = 0; j < size; j++)
		{
			if(arritem[i]==arritem[j])
			count++;

			if(count>mode)
			{
				mode=count;
				mode_indeks=j;
			}
		}
		
	}
	
	// TODO
	return arritem[mode_indeks];
}

/*
 * Parametre olarak verilen dizide elemanlardan
 * minimum k tanesini gonderir.
 * arritem: parametre olarak verilen dizi
 *   size : dizi boyutu
 *     k  : en kucuk kac eleman
 *  arrRes: en kucuk k elemani tasiyan dizi
 * Ornek: dizi={2,1,6,9,4,7}
 *        en kucuk 3 eleman: {1,2,4}
 */
void minimum_k_elements(int* arritem,int size,int k,int arrRes[k]){
 // TODO
 	
	 int i;
	int temp[size];
	for ( i = 0; i < size; i++)
	{
		temp[i]=arritem[i];
	}
	insertion_sort(temp,size);
	 for (int i = 0; i < k; i++)
	 {
		 arrRes[i]=temp[i];
		printf(" %d- ",arrRes[i]);
	 }
	
}

/*
 * Parametre olarak verilen bir diziden yeni bir dizi
 * olusturur. Yeni dizi tekrar eden sayilari icermez.
 * Diger sayilar da sirali olarak dizilir.
 * arritem : ayni elemanlari iceren dizi
 *    size : dizinin eleman sayisi
 *    dest : sonucta olusan dizi
 * Ornek: dizi = {2,3,5,1,7,2,3,5}
 *        sonuc= {1,2,3,5,7}
 */
void remove_duplications(int* arritem,int size,int* dest){
 //TODO
 	 int i; int k=1;
	 
	
}


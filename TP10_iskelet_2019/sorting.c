/*
 * sorting.c
 *
 *  Created on: Apr 18, 2019
 *      Author: Merve Unlu
 */


#include"sorting.h"

/*
    INSERTİON SELECTİTON VE BOUBLE SORT EN KÖTÜ KOŞULDA N'2 DE ÇALIŞIRLAR ANCAK SELECTİON SORT GEREKTİĞİ KADAR 
    YER DEĞİŞTİRME BU NEDENLE DAHA HIZLIDIR. OYSAKİ BOUBLE SORT HER ELEMAN İÇİN BİRDEN FAZLA YER DEĞŞTİRME YAPABİLİR
    SELECTİON SORT DİZİ SIRALI OLSA DA OLMASA DA AYNI PERFORMANSLA ÇALIŞIR.
*/
    
/*
 * Parametre olarak verilen dizi elemanlarini
 * insertion sort kullanarak siralar.
 * Sirali dizi olarak donus yapar.
 * BestCase O(n)
 * WorstCase O(n^2)
 */
void insertion_sort(int* arritem,int size){
	//TODO
    int i,j,t;
        for ( i = 1; i < size; i++)
        {
            j=i;
            while ((j>0)&& (arritem[j]<arritem[j-1]))
            {
                t=arritem[j];
                arritem[j]=arritem[j-1];
                arritem[j-1]=t;
                j--;
            }
            
        }
        
}


/*
 * Parametre olarak verilen diziyi
 * selection_sort kullanarak siralar.
 * Sirali dizi olarak donus yapar.
 * BestCase O(n^2)
 * WorstCase O(n^2)
 */
void selection_sort(int* arritem,int size){
   //TODO
   int i,j,t,min;
   for ( i = 0; i < size-1; i++)
   {
       min=i;
       for ( j = i+1; j < size; j++)
       {
           if(arritem[j]<arritem[min])
            min=j;
       }
       t=arritem[i];
       arritem[i]=arritem[min];
       arritem[min]=t;
       
   }
   
}

/*
 * Parametre olarak verilen diziyi
 * kabarcik siralamasi (bubble sort)
 * kullarak siralar.
 * Sirali dizi olarak donus yapar.
 * 
 * BestCase O(n)
 * WorstCase O(n^2)
 * 
 *  
 */
void bubble_sort(int* arritem,int size){
    //TODO
    
    int i,s,t; s=1;
    while (s)
    {
        s=0;
        for (i = 0; i < size-1; i++)
        {
            if(arritem[i]>arritem[i+1])
            {
                t=arritem[i];
                arritem[i]=arritem[i+1];
                arritem[i+1]=t;
                s=1;
            }
        }
        
    }
    
}

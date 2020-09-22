#include <stdlib.h>
#include <stdio.h>
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
int partition(int *array, int low, int high) {
// TODO 
    int pivot=high;
    int firsthigh= low;
    int i;
    for (int i = low; i < high; i++)
    {
        if(array[i]<=array[pivot])
        {
            swap(&array[i],&array[firsthigh]);
            firsthigh++;
        }
    }
swap(&array[pivot],&array[firsthigh]);
return(firsthigh); 
}

void qucik_s(int *array, int low,int high) {
// TODO 
    int pivot;
    if(low<high)
    {
        pivot=partition(array,low,high);
        qucik_s(array,low,pivot-1);
        qucik_s(array,pivot+1,high);
    }

}
void quick_sort_gsu(int *array, int size) {
// TODO 
    qucik_s(array,0,size-1);
}


void selection_sort(int* array,int size){
   //TODO
   int i,j,t,min;
   int *arritem=array;
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
void bubble_sort(int* array,int size){
    //TODO
    int *arritem=array;
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
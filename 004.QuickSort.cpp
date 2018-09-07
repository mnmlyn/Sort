//快速排序
void _QuickSort(int *arr,int s,int d)
{
    if(s >= d)return;
    int i=s-1,j;
    for(j=s;j<d;++j)
    {
        if(arr[j] < arr[d])
        {
            ++i;
            //swap
            if(i != j)
            {
                arr[i] ^= arr[j];
                arr[j] ^= arr[i];
                arr[i] ^= arr[j];
            }
        }
    }
    //here,i is the last element that less than d,i+1 is the first element that not less than d
    ++i;
    if(i != j)//j == d
    {
        arr[i] ^= arr[j];
        arr[j] ^= arr[i];
        arr[i] ^= arr[j];
    }
    _QuickSort(arr,s,i-1);
    _QuickSort(arr,i+1,d);
}

//快速排序
void QuickSort(int *arr,int n)
{
    _QuickSort(arr,0,n-1);
}
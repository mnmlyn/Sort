//选择排序
void SelectSort(int *arr,int n)
{
    int i,j,maxi;
    for(i=n-1;i>0;--i)
    {
        maxi = 0;
        for(j=1;j<=i;++j)
        {
            if(arr[j] > arr[maxi])maxi = j;
        }
        //swap maxi i
        if(maxi != i)
        {
            arr[maxi] ^= arr[i];
            arr[i] ^= arr[maxi];
            arr[maxi] ^= arr[i];
        }
    }
}
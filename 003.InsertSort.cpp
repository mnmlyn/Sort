//插入排序
void InsertSort(int *arr,int n)
{
    int i,j,numtoinsert;
    for(i=0;i<n;++i)
    {
        numtoinsert = arr[i];
        for(j=i-1;j>=0;--j)
        {
            if(arr[j] > numtoinsert)
            {
                arr[j+1] = arr[j];
            }
            else break;
        }
        arr[j+1] = numtoinsert;
    }
}
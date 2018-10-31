//冒泡排序
void BubbleSort(int *arr,int n)
{
    int i,j;
    for(i=n-1;i>0;--i)
    {
        for(j=0;j<i;++j)
        {
            if(arr[j] > arr[j+1])
            {
                //swap
                arr[j] ^= arr[j+1];
                arr[j+1] ^= arr[j];
                arr[j] ^= arr[j+1];
            }
        }
    }
}

//冒泡排序-优化-无交换直接退出
void BubbleSort_noexchangeexit(int *arr,int n)
{
    int i,j;
    bool flag;
    for(i=n-1;i>0;--i)
    {
        flag = false;
        for(j=0;j<i;++j)
        {
            if(arr[j] > arr[j+1])
            {
                flag = true;
                //swap
                arr[j] ^= arr[j+1];
                arr[j+1] ^= arr[j];
                arr[j] ^= arr[j+1];
            }
        }
        if(!flag)break;
    }
}


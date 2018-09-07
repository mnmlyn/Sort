//归并排序
#include <stdlib.h>//for malloc and free
#include <limits.h>//for INT_MAX

void Merge(int *arr,int s,int mid,int d)
{
    int n1=mid-s+1,n2=d-mid;//mid is belong to array n1
    int *arr1 = (int *)malloc(sizeof(int)*(n1+1));
    int *arr2 = (int *)malloc(sizeof(int)*(n2+1));
    int i,j,k;
    for(i=0;i<n1;++i)arr1[i] = arr[i+s];
    arr1[i]=INT_MAX;
    for(i=0;i<n2;++i)arr2[i] = arr[i+mid+1];
    arr2[i]=INT_MAX;
    i=0;
    j=0;
    for(k=s;k<=d;++k)
    {
        if(arr1[i] < arr2[j])
            arr[k] = arr1[i++];
        else
            arr[k] = arr2[j++];
    }
    free(arr1);
    free(arr2);
}

//归并排序
void _MergeSort(int *arr,int s,int d)
{
    if(s >= d)return;
    int mid = (s+d)/2;
    _MergeSort(arr,s,mid);
    _MergeSort(arr,mid+1,d);
    Merge(arr,s,mid,d);
}


//归并排序
void MergeSort(int *arr,int n)
{
    _MergeSort(arr,0,n-1);
}
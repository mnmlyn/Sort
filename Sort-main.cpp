#include "include/Sort-main.h"
#include <stdlib.h>//for rand srand

#define N 10

int main()
{
    using namespace std;

    int arr[N]={0};

    //init
    srand(1);
    for(int &x:arr)x=rand()%100;

    //print
    cout << "not sort arr\n";
    for(int x:arr)cout << x << " ";
    cout << endl;

    //sort
    //BubbleSort(arr,N);
    //BubbleSort_noexchangeexit(arr,N);
    //SelectSort(arr,N);
    //InsertSort(arr,N);
    //QuickSort(arr,N);
    //HeapSort(arr,N);
    MergeSort(arr,N);

    //print
    cout << "sorted arr\n";
    for(int x:arr)cout << x << " ";
    cout << endl;

    cout << "End\n";
    cin.get();
    return 0;
}
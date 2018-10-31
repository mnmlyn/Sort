#include "include/Sort-main.h"
#include <stdlib.h>//for rand srand

#define N 10


int main()
{
    using namespace std;

    A arrA[3] = {4,7,5};

    //print
    cout << "not sort arrA\n";
    for(A x:arrA)cout << x.id << " ";
    cout << endl;

    //sort
    BubbleSort(arrA,3);

    //print
    cout << "sorted arrA\n";
    for(A x:arrA)cout << x.id << " ";
    cout << endl;


    double arrdbl[N];
    //init
    srand(1);
    for(double &x:arrdbl)x=rand()%100/10.0;

    //print
    cout << "not sort arrdbl\n";
    for(double x:arrdbl)cout << x << " ";
    cout << endl;

    //sort
    BubbleSort(arrdbl,N);

    //print
    cout << "sorted arrdbl\n";
    for(double x:arrdbl)cout << x << " ";
    cout << endl;



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
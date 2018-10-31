#ifndef _SORT_TEMPLATE_H_
#define _SORT_TEMPLATE_H_
#include <stdlib.h>//for srand malloc free
#include <time.h>//for time
#include <string.h>//for memcpy

/* 使用函数模板来实现冒泡排序
 * 类型T应该有无参构造函数，operator<运算符，赋值运算符
 */
template <typename T>
void BubbleSort(T *arr,int n){
    int i,j,flag;
    T tmp;
    for(i=n-1;i>0;--i){
        flag = 0;
        for(j=0;j<i;++j){
            if(arr[j+1] < arr[j]){
                flag = 1;
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
        if(!flag)return;
    }
}

/* 使用函数模板来实现选择排序
 * 类型T应该有无参构造函数，operator<运算符，赋值运算符
 */
template <typename T>
void SelectSort(T *arr,int n){
    int i,j,maxi;
    T tmp;
    for(i=n-1;i>0;--i){
        for(maxi=0,j=1;j<=i;++j){
            if(arr[maxi] < arr[j]){
                maxi = j;
            }
        }
        if(maxi != i){
            tmp = arr[maxi];
            arr[maxi] = arr[i];
            arr[i] = tmp;
        }
    }
}

/* 使用函数模板来实现插入排序
 * 类型T应该有无参构造函数，operator<运算符，赋值运算符
 */
template <typename T>
void InsertSort(T *arr,int n){
    int i,j;
    T tmp;
    for(i=1;i<n;++i){
        tmp = arr[i];
        for(j=i-1;j>=0;--j){
            if(tmp < arr[j]){
                arr[j+1] = arr[j];
            }
            else break;
        }
        arr[j+1] = tmp;
    }
}

/* 使用函数模板来实现快速排序，将s到d之间的元素，变为以d处值为基准，小的在左，大的在右
 * 类型T应该有无参构造函数，operator<运算符，赋值运算符
 */
template <typename T>
int _QuickSort_BaseSort(T *arr,int s,int d){
    int i,j;
    T tmp;
    for(i=s,j=s;j<d;++j){
        if(arr[j] < arr[d]){
            //if(i != j){
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            //}
            ++i;
        }
    }
    tmp = arr[i];
    arr[i] = arr[d];
    arr[d] = tmp;
    return i;
}

/* 使用函数模板来实现快速排序，选取最后一个元素作为基准
 * 类型T应该有无参构造函数，operator<运算符，赋值运算符
 */
template <typename T>
void _QuickSort(T *arr,int s,int d){
    if(s >= d)return;
    int i = _QuickSort_BaseSort(arr,s,d);
    _QuickSort(arr,s,i-1);
    _QuickSort(arr,i+1,d);
}

/* 使用函数模板来实现快速排序，选取最后一个元素作为基准，包裹函数
 * 类型T应该有无参构造函数，operator<运算符，赋值运算符
 */
template <typename T>
void QuickSort(T *arr,int n){
    _QuickSort(arr,0,n-1);
}

/* 使用函数模板来实现快速排序，随机选取一个元素作为基准
 * 类型T应该有无参构造函数，operator<运算符，赋值运算符
 */
template <typename T>
void _QuickSort_RandomBase(T *arr,int s,int d){
    if(s >= d)return;
    srand(time(0));
    int basei = rand()%(d-s+1) + s;
    T tmp;
    tmp = arr[basei];
    arr[basei] = arr[d];
    arr[d] = tmp;
    int i = _QuickSort_BaseSort(arr,s,d);
    _QuickSort_RandomBase(arr,s,i-1);
    _QuickSort_RandomBase(arr,i+1,d);
}

/* 使用函数模板来实现快速排序，随机选取一个元素作为基准，包裹函数
 * 类型T应该有无参构造函数，operator<运算符，赋值运算符
 */
template <typename T>
void QuickSort_RandomBase(T *arr,int n){
    _QuickSort_RandomBase(arr,0,n-1);
}

/* 使用函数模板来实现堆排序，堆的定义
 * 类型T应该有无参构造函数，operator<运算符，赋值运算符
 */
template <typename T>
class Heap{
    public:
    int size;
    int cap;
    T *arr;
    Heap(T *_arr,int n):size(n),cap(n),arr(_arr){}
};

/* 使用函数模板来实现堆排序，调整堆
 * 类型T应该有无参构造函数，operator<运算符，赋值运算符
 */
template <typename T>
void HeapAdjust(Heap<T> &heap,int i){
    int lgst = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    T tmp;
    if(heap.size > left && heap.arr[lgst] < heap.arr[left])
        lgst = left;
    if(heap.size > right && heap.arr[lgst] < heap.arr[right])
        lgst = right;
    if(lgst != i){
        tmp = heap.arr[lgst];
        heap.arr[lgst] = heap.arr[i];
        heap.arr[i] = tmp;
        HeapAdjust(heap,lgst);
    }
}

/* 使用函数模板来实现堆排序，建堆
 * 类型T应该有无参构造函数，operator<运算符，赋值运算符
 */
template <typename T>
void HeapInit(Heap<T> &heap){
    int i;
    for(i=(heap.size-1)/2;i>=0;--i){
        HeapAdjust(heap,i);
    }
}

/* 使用函数模板来实现堆排序，排序
 * 类型T应该有无参构造函数，operator<运算符，赋值运算符
 */
template <typename T>
void HeapSort(T *arr,int n){
    Heap<T> heap(arr,n);
    HeapInit(heap);
    T tmp;
    while(--heap.size){
        tmp = heap.arr[heap.size];
        heap.arr[heap.size] = heap.arr[0];
        heap.arr[0] = tmp;
        HeapAdjust(heap,0);
    }
}

/* 使用函数模板来实现归并排序，合并操作
 * 类型T应该有无参构造函数，operator<运算符，赋值运算符
 */
template <typename T>
void _Merge(T *arr,int s,int mid,int d){
    int n1 = mid - s;
    int n2 = d - mid + 1;
    T *arr1 = (T*)malloc(sizeof(T)*n1);
    T *arr2 = (T*)malloc(sizeof(T)*n2);
    memcpy(arr1,arr+s,sizeof(T)*n1);
    memcpy(arr2,arr+mid,sizeof(T)*n2);
    int i=0,j=0,k;
    for(k=s;i<n1 && j<n2;++k){
        if(arr1[i] < arr2[j])
            arr[k] = arr1[i++];
        else 
            arr[k] = arr2[j++];
    }
    if(i >= n1)memcpy(arr+k,arr2+j,sizeof(T)*(n2-j));
    else if(j >= n2)memcpy(arr+k,arr1+i,sizeof(T)*(n1-i));
    free(arr1);
    free(arr2);
}

/* 使用函数模板来实现归并排序
 * 类型T应该有无参构造函数，operator<运算符，赋值运算符
 */
template <typename T>
void _MergeSort(T *arr,int s,int d){
    if(s >= d)return;
    int mid = (s+d)/2;
    _MergeSort(arr,s,mid);
    _MergeSort(arr,mid+1,d);
    _Merge(arr,s,mid+1,d);
}

/* 使用函数模板来实现归并排序，包裹函数
 * 类型T应该有无参构造函数，operator<运算符，赋值运算符
 */
template <typename T>
void MergeSort(T *arr,int n){
    _MergeSort(arr,0,n-1);
}

class A{
public:
    int id;
    A():id(0){}//冒泡排序中调用了无参构造函数，声明一个临时变量
    A(int _id):id(_id){}
    bool operator <(const A &b) const{//重载小于号运算符，供冒泡排序模板使用
        return this->id < b.id;
    }
};

#endif
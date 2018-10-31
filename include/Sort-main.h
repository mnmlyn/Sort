#ifndef _SORT_MAIN_H_
#define _SORT_MAIN_H_
#include <iostream>

//冒泡排序
void BubbleSort(int *arr,int n);
//冒泡排序-优化-无交换直接退出
void BubbleSort_noexchangeexit(int *arr,int n);
//使用函数模板来实现冒泡排序
#include "../001.BubbleSortTemplate.h"

//选择排序
void SelectSort(int *arr,int n);

//插入排序
void InsertSort(int *arr,int n);

//快速排序
void QuickSort(int *arr,int n);

//堆排序
void HeapSort(int *arr,int n);

//归并排序
void MergeSort(int *arr,int n);

#endif
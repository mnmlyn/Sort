#ifndef _SORT_TEMPLATE_H_
#define _SORT_TEMPLATE_H_

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

/* 使用函数模板来实现快速排序，选取最后一个元素作为基准
 * 类型T应该有无参构造函数，operator<运算符，赋值运算符
 */
template <typename T>
void _QuickSort(T *arr,int s,int d){
    if(s >= d)return;
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
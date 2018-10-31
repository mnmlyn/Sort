#ifndef _BUBBLE_SORT_TEMPLATE_H_
#define _BUBBLE_SORT_TEMPLATE_H_

//使用函数模板来实现冒泡排序
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
//堆排序
struct Heap{
    int size;
    int capacity;
    int *arr;
};

//调整堆
void HeapAdjust(struct Heap *heap,int i)
{
    int n=heap->size,left=2*i+1,right=2*i+2,largest=i;
    if(left < n && heap->arr[left] > heap->arr[largest])largest = left;
    if(right < n && heap->arr[right] > heap->arr[largest])largest = right;
    if(largest != i)
    {
        //swap
        heap->arr[largest] ^= heap->arr[i];
        heap->arr[i] ^= heap->arr[largest];
        heap->arr[largest] ^= heap->arr[i];
        HeapAdjust(heap,largest);
    }
}

//建堆
void HeapInit(struct Heap *heap)
{
    int i;
    heap->size = heap->capacity;
    for(i=(heap->capacity-1)/2;i >= 0;--i)
    {
        HeapAdjust(heap,i);
    }
}

//堆排序
void HeapSort(int *arr,int n)
{
    struct Heap heap;
    heap.capacity = n;
    heap.size = n;
    heap.arr = arr;
    int i;

    HeapInit(&heap);
    for(i=n-1;i>0;--i)
    {
        //swap
        heap.arr[0] ^= heap.arr[i];
        heap.arr[i] ^= heap.arr[0];
        heap.arr[0] ^= heap.arr[i];
        heap.size--;
        HeapAdjust(&heap,0);
    }
}
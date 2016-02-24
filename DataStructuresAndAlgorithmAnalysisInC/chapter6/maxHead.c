// 最大堆的实现
#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void max_heapify(int arr[], int i, int len)
{
    int leftIndex = 0;
    int rightIndex = 0;
    int largestIndex = 0;
    
    leftIndex = i * 2 + 1;
    rightIndex = i * 2 + 2;
    
    if (leftIndex < len) {
        if (leftIndex < len && arr[leftIndex] > arr[i]) {
            largestIndex = leftIndex;
        } else {
            largestIndex = i;
        }
        if (rightIndex < len && arr[rightIndex] > arr[largestIndex]) {
            largestIndex = rightIndex;
        }
        
        if (largestIndex != i) {
            swap(&arr[largestIndex], &arr[i]);
            max_heapify(arr, largestIndex, len);
        }
        // max_heapify(arr, leftIndex, len);
        // max_heapify(arr, rightIndex, len);
    }
}

void build_max_heap(int arr[], int len)
{
    int i = 0;
    for (i = len / 2; i >= 0; i--) {
        max_heapify(arr, i, len);
    }
}

void heapsort(int arr[], int len)
{
    int i = 0;
    build_max_heap(arr, len);
    for (i = len - 1; i >= 1; i--) {
        swap(&arr[0], &arr[i]);
        len -= 1;
        max_heapify(arr, 0, len);
    }
}
int main(void)
{
    int i = 0;
    int arr[10] = {11, 21, 13, 4, 15, 61, 17, 18, 9, 110};
    
    heapsort(arr, 10);
    
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    
    return 0;
}
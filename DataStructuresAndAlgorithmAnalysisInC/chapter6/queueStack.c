// 优先队列
#include <stdio.h>
#include <limits.h>

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

int heap_maximum( int arr[] )
{
    return arr[ 0 ];
}

int heap_extract_max( int arr[], int len )
{
    int maxNum = 0;
    if ( len < 1 ){
        printf("error! empty queue\n");
        return INT_MIN;
    }
    maxNum = arr[ 0 ];
    arr[ 0 ] = arr[ len - 1 ];
    len -= 1;
    max_heapify( arr, 0 , len );
    
    return maxNum;
}

void heap_increase_key( int arr[], int i, int key )
{
    if ( key < arr[ i ] ){
        printf("error! can not insert\n");
        return;
    }
    arr[ i ] = key;
    while ( i > 0 && arr[ i / 2 ] < arr[ i ] ){
        swap( &arr[ i ], &arr[ i / 2 ] );
        i /= 2;
    }
}

void max_heap_insert( int arr[], int len, int key )
{
    len += 1;
    arr[ len - 1 ] = INT_MIN;
    heap_increase_key( arr, len - 1, key );
}

int main( void )
{
    int i = 0;
    int arr[ 10 ];
    for ( i = 0; i < 10; i++ ){
        arr[ i ] = i;
    }
    
    build_max_heap( arr, 10 );
    
    for ( i = 0; i < 10; i++ ){
        printf("%d ", arr[ i ] );
    }
    printf("\n");
    printf("最大节点:%d\n", heap_extract_max( arr, 10 ) );
    printf("最大节点:%d\n", heap_extract_max( arr, 9 ) );
    heap_increase_key( arr, 5, 100 );
    printf("最大节点:%d\n", heap_maximum( arr ) );
    max_heap_insert( arr, 8, 9 );
    max_heap_insert( arr, 9, 8 );
    
    for ( i = 0; i < 10; i++ ){
        printf("%d ", arr[ i ] );
    }
    
    
    return 0;
}
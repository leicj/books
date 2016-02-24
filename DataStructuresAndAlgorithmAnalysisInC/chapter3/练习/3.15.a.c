// 自调整表的数组实现.
// 自调整表如同一个规则表.但是所有的插入都在表头进行,当一个元素被Find访问时,它就被移到表头而并不改变其余的项的相对顺序.
// 表头为数组的最后一个元素

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define N 100

// swap函数
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Find(int arr[], int val, int len)
{
    int i = 0;
    for (i = len - 1; i >= 0; i--) {
        if (val == arr[i]) {
            swap(&arr[len - 1], &arr[i]);
            break;
        }
    }
}

int main(void)
{
    int arr[N] = {};
    int i = 0;
    for (i = 0; i < N; i++) {
        arr[i] = i;
    }
    Find(arr, 10, N);
    Find(arr, 30, N);
    Find(arr, 50, N);
    Find(arr, -1, N);

    for (i = 0; i < N; i++) {
         printf("%d ", arr[i]);
         if ((i + 1) % 10 == 0) {
             printf("\n");
         }
    }

    return 0;
}

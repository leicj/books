// 插入排序

#include <stdio.h>

void insertsort(int arr[], int N)
{
    int i, p;
    int temp;

    for (p = 1; p < N; p++) {
        temp = arr[p];
        for (i = p; i >= 0 && arr[i - 1] > temp; i--) {
            arr[i] = arr[i - 1];
        }
        arr[i] = temp;
    }
}

int main(void)
{
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};

    insertsort(arr, 9);

    for (int i = 0; i < 9; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

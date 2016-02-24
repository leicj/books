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
    int arr[] = {4, 2, 6, 3, 1, 7, 6, 9, 0, 1};

    insertsort(arr, 10);

    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// 希尔排序

#include <stdio.h>

void print(int arr[], int N)
{
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void shellsort(int arr[], int N)
{
    int i, j, increment;
    int tmp;

    for (increment = N / 2; increment > 0; increment /= 2) {
        for (i = increment; i < N; i++) {
            tmp = arr[i];
            printf("tmp:%d, i:%d, increment:%d\n", tmp, i, increment);
            for (j = i; j >= increment; j -= increment) {
                if (tmp < arr[j - increment]) {
                    arr[j] = arr[j - increment];
                } else {
                    break;
                }
            }
            arr[j] = tmp;
            print(arr, N);
        }
    }
}

int main(void)
{
    int arr[] = {81, 94, 11, 96, 12, 35, 17, 95, 28, 58, 41, 75, 15};
    shellsort(arr, 13);

    for (int i = 0; i < 13; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

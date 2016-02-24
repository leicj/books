// Eratosthenes筛选法: 计算质数

#include <stdio.h>
#include <limits.h>
#define SIZE 10000

int main(void)
{
    int arr[SIZE] = {0, 0, 1};
    int i = 2;
    int j;
    for (i = 2; i < SIZE; i++) {
        arr[i] = 1;
    }
    i = 2;

    while (i < SIZE / 2) {
        j = i + 1;
        while (j < SIZE) {
            if (arr[j] && (j % i == 0)) {
                arr[j] = 0;
            }
            j++;
        }
        i++;
    }

    for (i = 2; i < SIZE; i++) {
        if (arr[i]) {
            printf("%d ", i);
        }
    }

    return 0;
}

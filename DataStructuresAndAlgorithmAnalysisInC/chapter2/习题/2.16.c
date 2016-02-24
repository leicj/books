// 不用递归,写出快速求幂的程序

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double myPow(int x, int N, int arr[], int len)
{
    double result = x;
    int index = 0;
    int i = 0;
    while (N > 0 && index < len) {
        if (N % 2 == 0) {
            arr[index] = 0;
        } else {
            arr[index] = 1;
        }
        index += 1;
        N = N / 2;
    }

    for (i = len - 1; i >=0; i--) {
        printf("%d ", arr[i]);
        if (arr[i] == 0) {
            result = result * result;
        } else {
            result = result * result * x;
        }
    }
    printf("\n");

    return result;
}

int main(void)
{
    int N = 31;
    int x = 3;
    int size = log10(N) / log10(2);
    int *arr = (int *)malloc(sizeof(int));
    double result = 0;
    result = myPow(x, N, arr, size);
    printf("%f\n", result);

    return 0;
}

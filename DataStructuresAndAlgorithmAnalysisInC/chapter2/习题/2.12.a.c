// 求最小子序列

#include <stdio.h>

int minSubseq(int arr[], int len)
{
    int minSub = 0;
    int minSum = 0;
    int i = 0;

    minSum = arr[0];
    for (i = 0; i < len; i++) {
        minSub += arr[i];
        if (minSub < minSum) {
            minSum = minSub;
        } else {
            minSub = 0;
        }
    }

    return minSum;
}

int main(void)
{
    int arr[] = {-2, 1, 3, -4, 6, -9, -3, 7};
    int minSum = 0;

    minSum = minSubseq(arr, 8);

    printf("min sum is: %d\n", minSum);

    return 0;
}

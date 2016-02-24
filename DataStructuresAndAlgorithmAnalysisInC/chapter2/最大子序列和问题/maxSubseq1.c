// 求解数组的最大子序列
// 输入: -2 11 -4 13 -5 -2时,答案为11-4+13=20

#include <stdio.h>

int maxSubSeq(int arr[], int len)
{
    int subSum, maxSum, i, j, k;
    subSum = 0;
    maxSum = 0;

    for (i = 0; i < len; i++) {
        for (j = i; j < len; j++) {
            subSum = 0;
            for (k = i; k <= j; k++) {
                subSum += arr[k];
            }
            if (subSum > maxSum) {
                maxSum = subSum;
            }
        }
    }
    return maxSum;
}

int main(void)
{
    int arr[] = {-2, 11, -4, 13, -5, -2};
    int maxSum = 0;

    maxSum = maxSubSeq(arr, 6);
    printf("maxSum is: %d\n", maxSum);

    return 0;
}

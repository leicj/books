// 求解数组的最大子序列
// 输入: -2 11 -4 13 -5 -2时,答案为11-4+13=20
// 最优算法: 扫描一次数组,记录最大子序列

#include <stdio.h>

int maxSubSeq(int arr[], int len)
{
    int i, subSum, maxSum;
    subSum = 0;
    maxSum = 0;
    for (i = 0; i < len; i++) {
        subSum += arr[i];
        if (subSum > maxSum) {
            maxSum = subSum;
        } else if (subSum < 0) {
            subSum = 0;
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

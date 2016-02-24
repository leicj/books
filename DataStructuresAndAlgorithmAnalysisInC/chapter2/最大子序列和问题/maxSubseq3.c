// 求解数组的最大子序列
// 输入: -2 11 -4 13 -5 -2时,答案为11-4+13=20
// 使用分治思想:
// 最大子序列出现在三处: 或者整个出现在输入数据的左半部,或者整个出现输入数据的右半部,要么就是中部
// 并且占据左右两部分

#include <stdio.h>

int max3(int a1, int a2, int a3)
{
    if ((a1 > a2) && (a1 > a3)) {
        return a1;
    } else if ((a2 > a1) && (a2 > a3)) {
        return a2;
    }
    return a3;
}

int maxSubSum(const int arr[], int left, int right)
{
    int maxLeftSum, maxRightSum;
    int maxLeftBorderSum, maxRightBorderSum;
    int leftBorderSum, rightBorderSum;
    int center, i;

    if (left == right) {
        if (arr[left] > 0) {
            return arr[left];
        } else {
            return 0;
        }
    }

    center = (left + right) / 2;
    maxLeftSum = maxSubSum(arr, left, center);
    maxRightSum = maxSubSum(arr, center + 1, right);

    maxLeftBorderSum = 0;
    leftBorderSum = 0;
    for (i = center; i >= left; i--) {
         leftBorderSum += arr[i];
         if (leftBorderSum > maxLeftBorderSum) {
             maxLeftBorderSum = leftBorderSum;
         }
    }
    maxRightBorderSum = 0;
    rightBorderSum = 0;
    for (i = center + 1; i <= right; i++) {
         rightBorderSum += arr[i];
         if (rightBorderSum > maxRightBorderSum) {
             maxRightBorderSum = rightBorderSum;
         }
    }

    return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
}

int maxSubSeq(int arr[], int len)
{
    return maxSubSum(arr, 0, len - 1);
}

int main(void)
{
    int arr[] = {-2, 11, -4, 13, -5, -2};
    int maxSum = 0;

    maxSum = maxSubSeq(arr, 6);
    printf("maxSum is: %d\n", maxSum);

    return 0;
}

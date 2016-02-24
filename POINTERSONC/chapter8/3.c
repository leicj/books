// 验证矩形是否为单位矩阵

#include <stdio.h>

int isMatrix(int arr[][10], int len)
{
    int i = 0;
    int j = 0;
    int sum = 0;
    int newsum = 0;
    for (i = 0; i < len; i++) {
        for (j = 0; j < 10; j++) {
            if (arr[i][j] == 0 || arr[i][j] == 1) {
                sum += arr[i][j];
            } else {
                return 0;
            }
            if (i == j) {
                newsum += arr[i][j];
            }
        }
    }

    if (sum != len) {
        return 0;
    }
    if (newsum != len) {
         return 0;
    }

    return 1;
}

int main(void)
{
    int arr[10][10];
    int i = 0;
    int j = 0;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (i == j) {
                arr[i][j] = 1;
            } else {
                 arr[i][j] = 0;
            }
        }
    }

    printf("%d\n", isMatrix(arr, 10));

    arr[3][5] = 1;
    printf("%d\n", isMatrix(arr, 10));

    return 0;
}

// 打印所有的素数

#include <stdio.h>

int main(void)
{
    int i = 0;
    int j = 0;
    int maxNum = 50;

    // 特殊素数2
    printf("2 ");
    for (i = 1; i <= 100; i++) {
        if (i < maxNum) {
            maxNum = i;
        } else {
            maxNum = 50;
        }
        for (j = 2; j < maxNum; j++) {
            if (0 == i % j) {
                break;
            }
        }
        if (j == maxNum) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}

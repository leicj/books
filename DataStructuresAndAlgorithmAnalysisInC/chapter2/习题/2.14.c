// Eratoshenes筛选法
// 从整数2开始到N,找出最小未被删除的整数i,打印i,然后删除i,2i,3i...i > 根号N时停止
// 但是我是在N / i处终止,而非根号N.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void eratosthenes(int N)
{
    int i = 0;
    int j = 0;
    int *arr = (int *)malloc(sizeof(N + 1));
    for (i = 0; i <= N; i++) {
        arr[i] = 1;
    }

    arr[2] = 1;
    for (i = 2; i <= N; i++) {
        if (arr[i] == 1) {
            for (j = i; j <= N / i; j++) {
                arr[j * i] = 0;
            }
        }
    }

    for (i = 2; i <= N; i++) {
        if (arr[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main(void)
{
    eratosthenes(100);

    return 0;
}

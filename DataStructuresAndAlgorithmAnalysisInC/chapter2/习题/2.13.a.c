// 测试素数
#include <stdio.h>

int isPrime(int x)
{
    int i = 0;
    if (x < 2) {
        return 0;
    }
    for (i = 2; i < x / 2; i++) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    int i;
    while (scanf("%d", &i) == 1) {
        if (isPrime(i)) {
            printf("%d is a prime number!\n", i);
        } else {
            printf("%d is a not prime number!\n", i);
        }
    }
}

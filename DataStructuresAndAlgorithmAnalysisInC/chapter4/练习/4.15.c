// 实现斐波拉切函数即可

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int Fib(int n)
{
    if (1 == n) {
        return 1;
    } else if (0 == n) {
        return 0;
    } else {
        return Fib(n - 1) + Fib(n - 2) + 1;
    }
}

int main(void)
{
    int i = 0;
    for (i = 1; i <= 15; i++) {
        printf("%d\n", Fib(i));
    }

    return 0;
}

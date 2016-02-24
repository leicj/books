// 使用递归式计算Hermite Polynomials

#include <stdio.h>

int hermite(int n, int x)
{
    if (n <= 0) {
        return 1;
    } else if (1 == n) {
        return 2 * x;
    } else {
        return 2 * x * hermite(n - 1, x) - 2 * (n - 1) * hermite(n - 2, x);
    }
}

int main(void)
{
    printf("%d\n", hermite(3, 2));
    printf("%d\n", hermite(3, 3));
    printf("%d\n", hermite(3, 4));

    return 0;
}

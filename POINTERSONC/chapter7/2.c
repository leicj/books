// 使用递归求最大公约数

#include <stdio.h>

int gcd(int m, int n)
{
    if (m <= 0 || n <= 0) {
        return 0;
    }
    if (m % n == 0) {
        return n;
    } else {
        return gcd(n, m % n);
    }
}

int main(void)
{
    printf("%d\n", gcd(24, 60));
    printf("%d\n", gcd(3, 97));
    printf("%d\n", gcd(60, 24));
    printf("%d\n", gcd(12345, 45635));

    return 0;
}

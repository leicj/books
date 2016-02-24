// 钢条切割的递归方案: 带备忘的自顶向下法
// 钢条的长度价格对应表:
// 长度i	1	2	3	4	5	6	7	8	9	10
// 价格pi	1	5	8	9	10	17	17	20	24	30
// 使用公式rn = max(pi + r(n-i)),1<=i<=n进行求解

#include <stdio.h>
#include <stdlib.h>

int memoizedCutRod(int p[], int n);
int memoizedCutRodAux(int p[], int n, int r[]);
int max(int a, int b)
{
    return (a > b ? a : b);
}
int main(void)
{
    int p[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int r = 0;

    for (int i = 1; i <= 10; i++) {
        r = memoizedCutRod(p, i);
        printf("i: %d, r: %d\n", i, r);
    }

    return 0;
}

int memoizedCutRod(int p[], int n)
{
    int *r = (int *)malloc(sizeof(int) * n);
    int i = 0;
    for (; i <= n; i++) {
         r[i] = -1;
    }

    return memoizedCutRodAux(p, n, r);
}

int memoizedCutRodAux(int p[], int n, int r[])
{
    int q = 0;
    if (r[n] >= 0) {
        return r[n];
    }
    if (0 == n) {
        return 0;
    }

    for (int i = 1; i <= n; i++) {
         q = max(q, p[i] + memoizedCutRodAux(p, n - i, r));
    }
    r[n] = q;
    return q;
}

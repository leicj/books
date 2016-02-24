// 求正数n的平方根

#include <stdio.h>

int main(void)
{
    int n;
    float prev = 1;   //前一个平方根
    float cur;        //当前的平方根
    float littleVal = 0.000000001; //两个平方根的最小间隔

    scanf("%d", &n);
    while (n > 0 && prev) {
        cur = (prev + n / prev) / 2;
        printf("%f\n", cur);
        if (cur - prev < littleVal) {
            break;
        } else {
            prev = cur;
        }
    }

    return 0;
}

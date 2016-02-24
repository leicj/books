// 判断三角形的类型

#include <stdio.h>

int main(void)
{
    int l1, l2, l3;

    scanf("%d %d %d", &l1, &l2, &l3);

    if (l1 <= 0 || l2 <= 0 || l3 <= 0) {
        printf("length should large than 0\n");
        return -1;
    }
    if (l1 + l2 < l3 || l1 + l3 < l2) {
        printf("it's not a three angle\n");
        return -1;
    }
    if (l1 == l2 && l1 == l3) {
        printf("等边三角形\n");
    } else if (l1 == l2 || l1 == l3 || l2 == l3) {
        printf("等腰三角形\n");
    } else {
        printf("不等边三角形\n");
    }

    return 0;
}

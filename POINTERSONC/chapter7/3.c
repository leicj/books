// 将字符串整数转换为整数
#include <stdio.h>

int strToInt(char *str)
{
    int num = 0;
    while (*str) {
        if (*str < '0' || *str > '9' ) {
            return 0;
        }
        num = num * 10 + *str - '0';
        str++;
    }

    return num;
}

int main(void)
{
    printf("%d\n", strToInt("12343"));
    printf("%d\n", strToInt("12a43"));
    printf("%d\n", strToInt("1212343"));
    printf("%d\n", strToInt("129878343"));

    return 0;
}

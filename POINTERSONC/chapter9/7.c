// char *my_strrchr(char const *str, int ch)
// 返回指向ch字符在str字符串中最后一次出现的位置的指针

#include <stdio.h>

char *my_strrchr(char const *str, int ch)
{
    char *temp = NULL;
    while (*str) {
        if (ch == *str) {
            temp = str;
        }
        str++;
    }

    return temp;
}

int main(void)
{
    char str[] = "hello world";
    printf("%s\n", my_strrchr(str, 'o'));

    return 0;
}

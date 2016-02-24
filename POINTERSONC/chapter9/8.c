// char *my_strnrchr(char const *str, int ch, int which)
// 返回指向ch字符在str字符串中第which次出现的位置的指针

#include <stdio.h>

char *my_strnchr(char const *str, int ch, int which)
{
    int num = 0;
    while (*str && num < which) {
        if (ch == *str) {
            num++;
        }
        str++;
    }

    if (num == which) {
        return --str;
    }

    return NULL;
}

int main(void)
{
    char str[] = "hello world";
    printf("%s\n", my_strnchr(str, 'o', 1));
    printf("%s\n", my_strnchr(str, 'o', 2));
    printf("%s\n", my_strnchr(str, 'o', 3));

    return 0;
}

// int count_chars(char const *str, char const *chars)
// 在第一个参数中进行查找,并返回匹配第二个参数所包含的字符的数量

#include <stdio.h>

int count_chars(char const *str, char const *chars)
{
    int count = 0;
    char *temp = NULL;
    while (*chars) {
        temp = str;
        while (*temp) {
            if (*temp == *chars) {
                count++;
            }
            temp++;
        }
        chars++;
    }

    return count;
}

int main(void)
{
    char str[] = "hello world";
    char chars[] = "helo";

    printf("counts:%d\n", count_chars(str, chars));

    return 0;
}

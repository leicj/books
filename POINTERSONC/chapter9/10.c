// int palindrome(char *string);
// 判断是否为回文,不区分大小写

#include <stdio.h>
#include <string.h>

int palindrome(char *str)
{
    char *temp = str;
    while (*temp) {
        temp++;
    }
    temp--;
    while (str < temp && tolower(*str++) == tolower(*temp--)) {
        ;
    }
    return str >= temp;
}

int main(void)
{
    char str[] = "HELLOAolleh";
    char str1[] = "hello world";
    printf("%d\n", palindrome(str));
    printf("%d\n", palindrome(str1));

    return 0;
}

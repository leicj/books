// 编写函数: 删除一个字符串的一部分.
// int del_substr(char *str, char const *substr);

#include <stdio.h>

int del_substr(char *str, char const *substr)
{
    char *tempstr = str;
    char *tempSubstr = substr;
    while (*tempstr) {
        while (*tempSubstr && *tempstr && *tempSubstr == *tempstr) {
            *tempSubstr++;
            *tempstr++;
        }
        if ('\0' == *tempstr) {
            return 0;
        }
        if ('\0' == *tempSubstr) {
            break;
        } else {
            tempstr = ++str;
            tempSubstr = substr;
        }
    }

    char *prevsub = tempstr - (tempSubstr - substr);
    while (*prevsub++ = *tempstr++) {
        ;
    }

    return 1;
}

int main(void)
{
    char str[8] = {'a', 'b', 'c', 'a', 'b', 'd', 'g', '\0'};
    char *substr = "abd";
    del_substr(str, substr);

    printf("%s\n", str);

    return 0;
}

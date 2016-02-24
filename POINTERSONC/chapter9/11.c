// 标准输入中,对the出现的次数进行统计

#include <stdio.h>

int count_chars(char *str, char *chars)
{
    int num = 0;
    char *temp = NULL;
    char *tempstr = NULL;
    while (*str) {
        tempstr = str;
        temp = chars;
        while (*tempstr == *temp) {
            tempstr++;
            temp++;
        }
        if (*tempstr == '\0') {
            break;
        }
        if (*temp == '\0' && *tempstr == ' ') {
            num++;
            str = tempstr;
        } else {
            if (*str != ' ') {
                while (*str && *str != ' ') {
                    str++;
                }
            } else {
                while (*str && *str == ' ') {
                    str++;
                }
            }
        }
    }

    return num;
}

int main(void)
{
     char str[100];
     char chars[] = "the";

     while (gets(str)) {
         printf("%d\n", count_chars(str, chars));
     }

     return 0;
}


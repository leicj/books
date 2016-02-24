// 反转字符串
// void reverse_string(char *str);

#include <stdio.h>

void reverse_string(char *str)
{
    char *temp = str;
    char ch;
    while (*temp) {
        *temp++;
    }
    *temp--;

    while (str < temp) {
        ch = *str;
        *str++ = *temp;
        *temp-- = ch;
    }
}

int main(void)
{
    char str[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', '\0'};
    reverse_string(str);

    printf("%s\n", str);

    return 0;
}

// 去除多个空格
#include <stdio.h>
#define SIZE 100

void delblank(char str[])
{
    int isSpace = 0;

    while (*str) {
        if (' ' == *str) {
            isSpace = 1;
            *str++;
            continue;
        }
        if (isSpace) {
            printf(" ");
            isSpace = 0;
        }
        printf("%c", *str);
        *str++;
    }
}

int main(void)
{
    char line[SIZE];
    while (gets(line)) {
        delblank(line);
        printf("\n");
    }

    return 0;
}

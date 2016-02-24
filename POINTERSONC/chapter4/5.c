// 从标准输入一行一行的读取文本,但如果有多行的文本内容相同,则打印其中一行

#include <stdio.h>
#include <string.h>
#define SIZE 128
// 判断两个字符串是否相等
int isEqual(char *str1, char *str2);
// copy
void copy(char *str1, char *str2);

int main(void)
{
    char prev[SIZE] = {'\0'};
    char cur[SIZE];
    char line[SIZE];
    char isSame = 0;

    while (gets(cur)) {
        if (isEqual(prev, cur)) {
            if (isSame) {
                continue;
            } else {
                copy(line, cur);
                isSame = 1;
            }
        } else {
            copy(prev, cur);
            if (isSame) {
                isSame = 0;
                printf("%s\n", line);
            }
        }
    }

    return 0;
}

int isEqual(char *str1, char *str2)
{
    while (*str1 && *str2 && *str1++ == *str2++) {
        ;
    }
    return '\0' == *str1 && '\0' == *str2;
}

void copy(char *str1, char *str2) {
    while (*str1++ = *str2++) {
        ;
    }
}

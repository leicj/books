// 一行行的读取输入行,然后打印最长的一行
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main(void)
{
    char largest[MAX_SIZE];//存储最长的一行
    char current[MAX_SIZE];//存储当前行
    int ch;
    int maxLen = 0;//存储最大长度
    int currentLen = 0;//存储当前行的长度

    while ((ch = getchar()) != EOF) {
        if ('\n' == ch) {
            current[currentLen] = '\0';
            if (currentLen > maxLen) {
                strncpy(largest, current, currentLen);
                maxLen = currentLen;
            }
            currentLen = 0;
        } else {
             current[currentLen++] = ch;
        }
    }

    printf("%s\n", largest);

    return 0;
}

// 编写函数实现:
// int substr(char dst[], char src[], int start, int len);
// 函数的任务是从src数组起始位置向后偏移start个字符的位置开始,最多复制len个非NUL字符到dst数组.
// 在复制完毕后,dst数组必须以NUL字节结尾,函数的返回值是存储于dst数组中的字符串的长度.
// 如果start所指定的位置越过了src数组的尾部,或者start或len的值为负数,那么复制到dst数组的是一个空字符串.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100

int mysubstr(char dst[], char src[], int start, int len)
{
    int last = len;
    if (start < 0 || len < 0 || start > strlen(src)) {
        *dst = '\0';
        return 0;
    }

    while (start--) {
        *src++;
    }
    while ((len--) && (*dst++ = *src++)) {
        ;
    }
    return (last - len);
}

int main(void)
{
    char src[SIZE];
    char dst[SIZE] = {'\0'};
    int len = 0;

    while (gets(src)) {
        len = mysubstr(dst, src, 2, 5);
        printf("%d: %s\n", len, dst);
        len = mysubstr(dst, src, 2, 10);
        printf("%d: %s\n", len, dst);
        len = mysubstr(dst, src, 2, -1);
        printf("%d: %s\n", len, dst);
    }

    return 0;
}

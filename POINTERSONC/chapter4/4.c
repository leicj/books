// 实现copy_n(char dst[], char src[], int n)函数
// 这个函数用于把一个字符串从数组src复制到数组dst,但有如下要求:
// 必须正好复制n个字符到dst数组中.如果src字符串的长度小于n,补空格.如果src的长度大于或等于n,那么复制n个字符即可.

#include <stdio.h>
#define SIZE 100
void copy_n(char dst[], char src[], int n)
{
    int index = 0;
    while ((index++ < n) && (*dst++ = *src++)) {
        ;
    }
    *dst = '\0';
}

int main(void)
{
    char dst[SIZE];
    char src[SIZE];

    while (gets(src)) {
        copy_n(dst, src, 6);
        printf("%s\n", dst);
    }

    return 0;
}

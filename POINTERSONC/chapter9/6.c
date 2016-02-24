// char *my_strcpy_end(char *dst, char *source);
// 返回指向目标字符串末尾的指针

#include <stdio.h>

char *my_strcpy_end(char *dst, char *source)
{
    while (*dst++ = *source++) {
        ;
    }
    return dst;
}

int main(void)
{
    char dst[20];
    char str[] = "hello world";
    char *temp = NULL;

    temp = my_strcpy_end(dst, str);
    printf("len:%d\n", temp - dst - 1);

    return 0;
}



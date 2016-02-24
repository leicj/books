// 不会溢出的复制函数
// my_strcpy(char *dst, char const *source)

#include <stdio.h>

void my_strcpy(char *dst, char const *source)
{
    while (*dst && (*dst++ = *source++)) {
        ;
    }
}

int main(void)
{
    char dst[] = "hello world";
    char source[] = "i love this world";

    my_strcpy(dst, source);

    printf("%s\n", dst);

    return 0;
}

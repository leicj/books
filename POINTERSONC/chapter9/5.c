// void my_strncat(char *dst, char const *source, int len);
#include <stdio.h>
#include <string.h>

void my_strncat(char *dst, char const *source, int len)
{
    int sublen = strlen(dst);
    dst = dst + sublen;
    while (sublen < len && (*dst++ = *source++)) {
        sublen++;
    }
    if (sublen == len) {
        *dst = '\0';
    }
}

int main(void)
{
    char dst[20];
    char str1[] = "hello ";
    char str2[] = "world.";
    char str3[] = "i love this world";

    my_strncat(dst, str1, 20);
    printf("%s\n", dst);
    my_strncat(dst, str2, 20);
    printf("%s\n", dst);
    my_strncat(dst, str3, 20);
    printf("%s\n", dst);

    return 0;
}

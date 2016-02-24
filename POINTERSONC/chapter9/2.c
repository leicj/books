// my_strlen函数
// size_t my_strlen(char *str, int len);
// 字符串的最大长度为len,解决str中没有以NUL结尾而导致strlen无限长的BUG

#include <stdio.h>
#include <limits.h>
#include <string.h>

size_t my_strlen(char *str, int len)
{
    int length = 0;
    for (; length < len; length++) {
        if (*str++ == '\0') {
            break;
        }
    }
    return length;
}

int main(void)
{
    char str1[1000] = "jfkdalsjfkldsjiorewhfksaljfiewhjfkdsafjaiwoejf";
    char str2[] = "hello world i love this world";
    int len1 = 0;
    int len2 = 0;

    strncpy(str1, str2, 10);
    len1 = strlen(str1);
    len2 = my_strlen(str1, 10);

    printf("len1: %d\nlen2: %d\n", len1, len2);

    return 0;
}

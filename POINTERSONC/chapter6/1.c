// 编写一个函数: 它在一个字符串中进行搜索,查找所有在一个给定字符集合中出现的字符
// char *find_char(char const *source, char const *chars);
// 它的基本想法是查找source字符串中匹配chars字符串中任何字符的第一个字符,函数然后返回一个指向source中第一个匹配所找到的位置的指针.如果source中的所有字符均不匹配,
// chars中的任何字符,函数就返回一个NULL指针.如果任何一个参数为NULL,或任何一个参数所指向的字符串为空,函数也返回一个NULL指针.

#include <stdio.h>
#define SIZE 100

char *find_char(char const *source, char const *chars)
{
    char *temp = NULL;
    if (NULL == *source || NULL == *chars) {
        return NULL;
    }

    while (*chars) {
        temp = source;
        while (*temp) {
            if (*chars == *temp) {
                return temp;
            }
            *temp++;
        }
        *chars++;
    }

    return NULL;
}

int main(void)
{
     char *source = "ABCDEFGH";
     char *chars = "XRCQEF";

     printf("%s\n", find_char(source, chars));

     return 0;
}

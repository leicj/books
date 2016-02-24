// 从标准输入读取字符,并把它写到标准输出中
// 字母字符进行加密
// 加密的方法: 每个字母被修改为在字母表上距离其13个位置(前或后)

#include <stdio.h>

int main(void)
{
    int ch;

    while ((ch = getchar()) != EOF) {
        if (ch >= 'a' && ch <= 'z') {
            if (ch + 13 > 'z') {
                putchar(ch - 13);
            } else {
                putchar(ch + 13);
            }
            continue;
        }
        if (ch >= 'A' && ch <= 'Z') {
            if (ch + 13 > 'Z') {
                putchar(ch - 13);
            } else {
                putchar(ch + 13);
            }
            continue;
        }
        putchar(ch);
    }

    return 0;
}

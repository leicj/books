// 从标准输入读取几行,输出时加上行号
// 不限制输入字符的长度
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int c;
    int col = 1;
    int isLine = 1;

    while ((c = getchar()) != EOF) {
        if (1 == isLine) {
            printf("%d:", col);
        }
        if ('\n' == c) {
            col += 1;
            printf("\n");
            isLine = 1;
            continue;
        }
        printf("%c", c);
        isLine = 0;
    }

    return 0;
}

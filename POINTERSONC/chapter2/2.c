// 验证标准输入的源代码,花括号是否成对出现
#include <stdio.h>

int main(void)
{
    int leftNum = 0;
    int rightNum = 0;
    int ch;
    {
        while ((ch = getchar()) != EOF) {
            if ('{' == ch) {
                leftNum++;
            } else if ('}' == ch) {
                rightNum++;
            }
        }
    }

    printf("left number is:%d\nright number is:%d\n", leftNum, rightNum);

    return 0;
}

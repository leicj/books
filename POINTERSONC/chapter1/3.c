// 输入字符串,输出其checksum值

#include <stdio.h>

int main(void)
{
    signed char checksum = -1;
    int ch;

    while ((ch = getchar()) != EOF) {
        checksum += ch;
        if ('\n' == ch) {
            printf("%d\n", checksum);
            checksum = -1;
        }
    }

    return 0;
}

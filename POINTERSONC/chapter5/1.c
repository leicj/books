// 将大写字母转换为小写字母
#include <stdio.h>

int main(void)
{
    int ch;

    while ((ch = getchar()) != EOF) {
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch - 'A' + 'a';
        }
        putchar(ch);
    }

    return 0;
}

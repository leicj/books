// 读取各个字符所占用的百分比

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int cn = 0;     //控制字符
    int space = 0;  //空白字符
    int num = 0;    //数字
    int lower = 0;  //小写字母
    int upper = 0;  //大写字母
    int punct = 0;  //标点符号
    int print = 0;  //可打印字符
    int other = 0;  //其他字符

    int sum = 0;
    int ch;
    while ((ch = getchar()) != EOF) {
        sum += 1;
        if (iscntrl(ch)) {
            cn++;
        } else if (isspace(ch)) {
            space++;
        } else if (isdigit(ch)) {
            num++;
        } else if (islower(ch)) {
             lower++;
        } else if (isupper(ch)) {
            upper++;
        } else if (ispunct(ch)) {
            punct++;
        } else if (isprint(ch)) {
            print++;
        } else {
             other++;
        }
    }
    printf("控制字符:%.2f%%\n", cn * 100.0 / sum);
    printf("空白字符:%.2f%%\n", space * 100.0 / sum);
    printf("数字:%.2f%%\n", num * 100.0 / sum);
    printf("小写字母:%.2f%%\n", lower * 100.0 / sum);
    printf("大写字母:%.2f%%\n", upper * 100.0 / sum);
    printf("标点符号:%.2f%%\n", punct * 100.0 / sum);
    printf("可打印字符:%.2f%%\n", print * 100.0 / sum);
    printf("其他字符:%.2f%%\n", other * 100.0 / sum);

    return 0;
}

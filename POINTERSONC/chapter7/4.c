// max_list: 返回任意数目的整型参数的最大值
#include <stdio.h>
#include <stdarg.h>

int max_value(int nValue, ...)
{
    va_list var_arg;
    int maxValue = nValue;
    int tempValue;
    va_start(var_arg, nValue);

    while ( ( tempValue = va_arg( var_arg, int ) ) > 0 ){
        if ( tempValue > maxValue ){
            maxValue = tempValue;
        }
    }

    va_end( var_arg );

    return maxValue;
}

int main(void)
{
    printf("%d\n", max_value( 2, 4, 6, 8, 10, 1, 3, 5, 7, 9, -1 ));

    return 0;
}

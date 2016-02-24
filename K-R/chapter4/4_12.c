#include <stdio.h>
 
void itoa( int n, char *str, int base )
{
    static i = 0;       //这里用到数组的索引而不是用到指针是因为指针递增后找不到字符串数组的起始位置了.
    if ( n < 0 ){
        str[ i++ ] = '-';
    }
    if ( n / base ){
        itoa( n / base, str, base );
    }
    str[ i++ ] = n % base + '0';
    str[ i ] = '\0';        //这步有点浪费,如果数组初始化为'\0'就可以了.
}
 
int main(void)
{
    char    str[128];
    int     i = 0;
    for ( i = 0; i < 128; i++ ){
        str[ i ] = ' ';
    }
    itoa( 12345, str, 10 );
 
    printf("%s\n", str );
 
    return 0;
}

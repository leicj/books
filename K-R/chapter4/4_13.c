#include <stdio.h>
#include <string.h>
 
void subreverse( char *str, int start, int end )
{   
    if ( start <= end ){
        char ch = str[ start ];
        str[ start++ ] = str[ end ];
        str[ end-- ] = ch;
        subreverse( str, start, end );
    }
}
 
void reverse( char *str )
{
    int len = strlen( str ) - 1;
    subreverse( str, 0, len );
}
 
int main(void)
{
    char    str[] = "hello world";
    reverse( str );
 
    printf("%s\n", str );
 
    return 0;
}

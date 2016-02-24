#include <stdio.h>
 
void myLower( char *str )
{
    while ( '\0' != *str ){
        *str = ( *str >= 'A' && *str <= 'Z' ) ? ( *str + 'a' - 'A' ) : *str;
        str++;
    }
}
 
int main(void)
{
    char str[] = "HElLo, WoRlD";
    myLower( str );
    printf("%s\n", str );
 
    return 0;
}
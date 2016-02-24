#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *strcopy( char const *str ){
    int len = strlen( str );
    char    *arr = malloc( len + 1 );

    if ( NULL != arr ){
        strcpy( arr, str );
    }

    return arr;
}

int main(void)
{
    printf("%s\n", strcopy( "hello world" ) );

    return 0;
}

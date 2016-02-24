#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int     *arr;
    int     *temp;
    int     i;
    int     len = 0;
    if ( scanf( "%d", &len ) != 1 ){
        printf("error\n");
        exit( EXIT_FAILURE );
    }

    arr = malloc( len * sizeof( int ) );
    temp = arr;
    while ( ( scanf("%d", &i) ) == 1 && i != EOF ){
        *temp++ = i;
    }
    for ( i = 0; i < len; i++ ){
        printf("%d ", arr[i]);
    }

    printf("\n");
    free( arr );

    return 0;
}

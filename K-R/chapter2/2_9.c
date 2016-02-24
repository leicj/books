#include <stdio.h>
 
int bitcount( unsigned x )
{
    int b;
    for ( b = 0; x != 0; x &= x - 1 ){
        b++;
    }
 
    return b;
}
 
int main(void)
{
    printf("%d\n", bitcount( 94 ) );
 
    return 0;
}
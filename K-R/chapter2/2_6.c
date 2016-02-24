#include <stdio.h>
 
unsigned int setbits( int x, int p, int n, int y )
{
    return ( ( x >> p ) & ( ~( ~0 << n ) ) | ( ( y >> n ) << n ) );
}
 
int main(void)
{
    printf("%d\n", setbits( 94, 3, 4, 164 ) );
 
    return 0;
}
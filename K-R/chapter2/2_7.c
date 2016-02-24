#include <stdio.h>
 
unsigned int invert( int x, int p, int n )
{
    return ( x >> ( p + n ) << ( p + n ) ) + ( ( ~( x >> p ) & ~( ~0 << n ) ) << p ) + ( x & ( ~( ~0 << p ) ) ); 
}
 
int main(void)
{
    printf("%d\n", invert( 94, 3, 4 ) );
 
    return 0;
}
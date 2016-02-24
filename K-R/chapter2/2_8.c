#include <stdio.h>
 
unsigned int rightrot( int x, int n )
{
    int tempNum = x;
    int numOfBit = 0;
    while ( tempNum ){
        numOfBit++;
        tempNum /= 2;
    }
    while ( n-- ){
        x = ( ( x & ~( 1 << ( numOfBit - 1 ) ) ) << 1 ) + ( x >> ( numOfBit - 1 ) );
    }
 
    return x;
}
 
int main(void)
{
    printf("%d\n", rightrot( 94, 4 ) );
 
    return 0;
}
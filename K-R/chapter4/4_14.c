#include <stdio.h>
#include <string.h>
 
#define swap( t, x, y ) { t temp; temp = x; x = y; y = temp; }
 
int main(void)
{
    int i = 3;
    int j = 4;
    float m = 5.5;
    float n = 6.6;
    swap( int, i, j );
    swap( float, m, n );
 
    printf("%d--%d\n", i, j );
    printf("%.2f--%.2f\n", m, n );
 
    return 0;
}

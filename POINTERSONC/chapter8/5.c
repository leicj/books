#include <stdio.h>

void matrix_multiply( int (*m1)[2], int (*m2)[4], int (*r)[4], int x, int y, int z )
{
    int i = 0;
    int j = 0;
    int k = 0;
    int m = 0;
    int n = 0;
    for ( i = 0; i < x; i++ ){
        for ( j = 0; j < z; j++ ){
            for ( k = 0; k < y; k++ ){
                r[m][n] += m1[i][k] * m2[k][j];
            }
            n++;
        }
        m++;
        n = 0;      //记得清零
    }
}

int main(void)
{
    int m1[3][2] = { 2, -6, 3, 5, 1, -1 };
    int m2[2][4] = { 4, -2, -4, -5, -7, -3, 6, 7 };
    int r[3][4];
    int i = 0;
    int j = 0;

    for ( i = 0; i < 3; i++ ){
        for ( j = 0; j < 4; j++ ){
            r[i][j] = 0;
        }
    }

    matrix_multiply( m1, m2, r, 3, 2, 4 );
    for ( i = 0; i < 3; i++ ){
        for ( j = 0; j < 4; j++ ){
            printf("%d ", r[i][j]);
        }
        printf("\n");
    }

    return 0;
}

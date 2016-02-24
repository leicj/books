#include <stdio.h>
int count = 0;

int isSafe(int rows[8], int x, int y) {
    int i = 0;
    for (i = 1; i <= y; i++) {
        if (rows[y - i] == x || rows[y - i] == x - i || rows[y - i] == x + i) {
            return 0;
        }
    }
    return 1;
}

void print(int rows[])
{
    for (int i = 0; i < 8; i++) {
        printf("%d ", rows[i]);
    }
    printf("\n");
}
void Queen(int rows[], int y)
{
    int x = 0;
    for (x = 0; x < 8; x++) {
        if (isSafe(rows, x, y)) {
            rows[y] = x;
            if (7 == y) {
                count++;
                print(rows);
            } else {
                Queen(rows, y + 1);
            }
        }
    }
}
int main(void)
{
    int rows[8];

    Queen(rows, 0);

    printf("%d\n", count);

    return 0;
}

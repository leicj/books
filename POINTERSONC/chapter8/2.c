#include <stdio.h>

int main(void)
{
    float fValue;

    while (1 == scanf("%f", &fValue)) {
        if (fValue >= 0 && fValue <= 23350) {
            printf("%f\n", fValue * 0.15);
        } else if (fValue >= 23350 && fValue <= 56550) {
            printf("%f\n", 3502.5 + fValue * 0.28);
        } else if (fValue >= 56550 && fValue <= 117950) {
            printf("%f\n", 12798.50 + fValue * 0.31);
        } else if (fValue >= 117950 && fValue <= 256500) {
            printf("%f\n", 31832.50 + fValue * 0.36);
        } else {
            printf("%f\n", 81710.50 + fValue * 0.396);
        }
    }

    return 0;
}

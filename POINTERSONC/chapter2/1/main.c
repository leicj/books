#include <stdio.h>

int main(void)
{
    printf("%d\n", increment(10));
    printf("%d\n", increment(0));
    printf("%d\n", increment(-10));
    printf("%d\n", negate(10));
    printf("%d\n", negate(0));
    printf("%d\n", negate(-10));

    return 0;
}

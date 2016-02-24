// 函数unsigned int reverse_bits(unsigned int value);
// 此函数的返回值是把value的二进制位模式从左到右变换一下后的值

#include <stdio.h>

unsigned int reverse_bits(unsigned int value)
{
    unsigned int tempValue = 0;
    int n = sizeof(unsigned int) * 8 - 1;
    int i = 0;
    while (i < n) {
        tempValue += (value & (1 << i) ? 1 : 0) << (n - i);
        i++;
    }

    return tempValue;
}

int main(void)
{
    unsigned int value = 25;
    printf("%x\n", reverse_bits(value));

    return 0;
}

// 编写函数: 把一个给定的值存储到一个整数中指定的几个位
// int store_bit_field(int original_value, int value_to_store, unsigned starting_bit, unsigned ending_bit);

#include <stdio.h>
#include <stdlib.h>

int store_bit_field( int original_value, int value_to_store, unsigned starting_bit, unsigned ending_bit ){
    int maskValue = 0;
    int maskValueForStore = 0;
    int new_value_to_store = 0;
    int i = 0;
    for ( i = ending_bit; i <= starting_bit; i++ ){
        maskValue += 1 << i;
        maskValueForStore += 1 << (i - ending_bit);
    }
    printf("%x--%x\n", maskValue, maskValueForStore);
    original_value &= ~maskValue;
    value_to_store &= maskValueForStore;
    value_to_store <<= ending_bit;
    return original_value | value_to_store;
}

int main(void)
{
	int value = store_bit_field( 0xffff, 0x123, 13, 9 );
	printf("%x\n", value);

    return 0;
}

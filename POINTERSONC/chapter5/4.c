// 编写一组函数
// 将指定的位设置为1
// void set_bit(char bit_array[], unsigned bit_number);
// 将指定的位清零
// void clear_bit(char bit_array[], unsigned bit_number);
// 如果value的值为0,则将指定的位清0,否则置1
// int test_bit(char bit_array[], unsigned bit_number);
// 如果参数中指定的位不是0,函数就返回真,否则返回假

#include <stdio.h>
#define SIZE 10

void set_bit(char bit_array[], unsigned bit_number)
{
    bit_array[bit_number] = '1';
}

void clear_bit(char bit_array[], unsigned bit_number)
{
    bit_array[bit_number] = '0';
}

void assign_bit(char bit_array[], unsigned bit_number, int value)
{
    if (0 == value) {
        bit_array[bit_number] = '0';
    } else {
         bit_array[bit_number] = '1';
    }
}

int test_bit(char bit_array[], unsigned bit_number)
{
    return '0' == bit_array[bit_number];
}

int main(void)
{
    char bit_array[SIZE + 1];
    int i = 0;
    for (i = 0; i < SIZE; i++) {
         bit_array[i] = '0';
    }
    bit_array[SIZE] = '\0';

    set_bit(bit_array, 5);
    printf("%s\n", bit_array);

    clear_bit(bit_array, 5);
    printf("%s\n", bit_array);

    assign_bit(bit_array, 5, 0);
    printf("%s\n", bit_array);
    assign_bit(bit_array, 5, 1);
    printf("%s\n", bit_array);

    printf("%d--%d\n", test_bit(bit_array, 5), test_bit(bit_array, 6));

    return 0;
}

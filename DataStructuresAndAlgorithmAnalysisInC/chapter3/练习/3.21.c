// 使用一个数组实现两个堆栈
// 一个堆栈从数组头部插入,一个从数组尾部插入即可.
// 但是如果其中一个堆栈已满,则需要将整个数据进行迁移.
// 如果整个数组已满,则提示栈溢出

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
int arr[SIZE];
int top1 = SIZE / 2;   //第一个堆栈的栈顶
int top2 = SIZE / 2 + 1; //第一个堆栈的最大栈深度
int tail1 = SIZE / 2; // 第二个堆栈的栈顶
int tail2 = SIZE / 2 + 1; // 第二个堆栈的最大栈深度

// 插入第一个栈
void insert1(int val);
// 插入第二个栈
void insert2(int val);
// 打印第一个栈
void print1();
// 打印第二个栈
void print2();

int main(void)
{
    insert1(1);
    insert1(2);
    insert1(3);
    insert1(4);
    insert1(5);
    insert1(6);
    insert1(7);
    insert2(1);
    insert2(2);
    insert2(3);
    insert2(4);

    print1();
    print2();

    return 0;
}

void insert1(int val)
{
    int i = 0;
    if (top1 >= 0) {
        arr[top1--] = val;
    } else {
        // 判断第二个堆栈是否已满.如果未满,则将第二个堆栈借一个空间,否则报堆栈溢出
        if (top2 < SIZE) {
            for (i = top2 - 1; i >= tail2; i--) {
                arr[i] = arr[i - 1];
            }
            for (i = tail1 + 1; i >= 0; i--) {
                arr[i] = arr[i - 1];
            }
            arr[0] = val;
            top1 = -1;
            tail1 += 1;
            tail2 += 1;
            top2 += 1;
        } else {
            printf("stack 1 insert: 堆栈溢出!\n");
        }
    }
}

void insert2(int val)
{
    int i = 0;
    if (top2 <= SIZE - 1) {
        arr[top2++] = val;
    } else {
        if (top1 >= 0) {
            for (i = top1; i <= tail1; i++) {
                arr[i] = arr[i + 1];
            }
            for (i = tail2 - 1; i < top2; i++) {
                arr[i] = arr[i + 1];
            }
            arr[SIZE - 1] = val;
            top1 -= 1;
            tail1 -= 1;
            tail2 -= 1;
            top2 -= 1;
        } else {
            printf("stack 2 insert: 堆栈溢出!\n");
        }
    }
}

void print1()
{
    int i = 0;
    printf("stack 1: ");
    for (i = tail1; i > top1; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void print2()
{
    int i = 0;
    printf("stack 2: ");
    for (i = tail2; i < top2; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

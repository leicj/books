// 队列的数组实现
// 使用循环数组结构

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 5
int queue[SIZE];
int top = 0;
int tail = 0;

// 判断是否为空队列
int isEmpty()
{
    return top == tail;
}
// 判断是否为满队列
int isFull()
{
    if (tail == 0 && top == SIZE - 1) {
        return 1;
    }
    return top == tail - 1;
}
// 入队
void push(int val)
{
    if (isFull()) {
        printf("queue full\n");
        return;
    }
    queue[top] = val;
    if (top == SIZE - 1) {
        top = 0;
    } else {
        top++;
    }
}
// 出队
int pop()
{
    int result = 0;
    if (isEmpty()) {
        printf("queue empty\n");
        return INT_MIN;
    }
    result = queue[tail];
    if (tail == SIZE) {
        tail = 0;
    } else {
        tail++;
    }
    return result;
}
// 打印队列
void print()
{
    int i = 0;
    if (top > tail) {
        for (i = tail; i < top; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for (i = tail; i < SIZE; i++) {
            printf("%d ", queue[i]);
        }
        for (i = 0; i < top; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

int main(void)
{
    int i = 0;
    for (i = 0; i < 6; i++) {
        push(i);
    }
    print();

    pop();
    pop();
    push(11);
    push(12);
    print();

    return 0;
}

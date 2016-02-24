// 栈的数组实现
// 使用结构体,动态创建数组的大小

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct STACK {
    int cap;
    int top;
    int *arr;
}Stack;

// 创建数组
Stack *create(int MaxElement);
// 释放数组
void dispose(Stack *s);
// 判断数组是否为空
int isEmpty(Stack *s);
// 判断数组是否已满
int isFull(Stack *s);
// 创建一个空栈
void makeEmpty(Stack *s);
// push
void push(Stack *s, int val);
// pop
void pop(Stack *s);
// top
int top(Stack *s);

int main(void)
{
    Stack *stack = NULL;

    stack = create(5);
    makeEmpty(stack);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    push(stack, 6);

    printf("top is: %d\n", top(stack));
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);

    return 0;
}
// 创建数组
Stack *create(int MaxElement)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (NULL == stack) {
        printf("error memory!\n");
        return NULL;
    }
    stack->cap = MaxElement;
    stack->top = -1;
    stack->arr = (int *)malloc(sizeof(int) * MaxElement);
    if (NULL == stack->arr) {
         printf("error memory!\n");
         return NULL;
    }

    return stack;
}
// 释放数组
void dispose(Stack *s)
{
    if (s) {
        free(s->arr);
        free(s);
    }
}
// 判断数组是否为空
int isEmpty(Stack *s)
{
    return s && s->top == -1;
}
// 判断数组是否已满
int isFull(Stack *s)
{
    return s && s->cap == s->top + 1;
}
// 创建一个空栈
void makeEmpty(Stack *s)
{
    if (s) {
        s->top = -1;
    }
}
// push
void push(Stack *s, int val)
{
    if (s && !isFull(s)) {
        s->arr[++s->top] = val;
    } else {
         printf("full stack!\n");
    }
}
// pop
void pop(Stack *s)
{
    if (s && -1 == s->top) {
        printf("empty stack!\n");
        return;
    }
    s->top--;
}
// top
int top(Stack *s)
{
    if (!isEmpty(s)) {
        return s->arr[s->top];
    }
    return INT_MIN;
}

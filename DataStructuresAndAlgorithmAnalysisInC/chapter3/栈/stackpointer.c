// 栈的指针实现
// 所有的栈操作,均在链表的头部进行插入删除
// 存在root指针,指向栈的链表

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct STACK {
    struct STACK *next;
    int val;
} Stack;

// 插入操作
void push(Stack *stack, int val);
// 删除操作
Stack *pop(Stack *stack);
// 返回栈顶元素
Stack *top(Stack *stack);

int main(void)
{
    int i = 0;
    Stack *root = (Stack *)malloc(sizeof(Stack));
    root->next = NULL;
    root->val = INT_MIN;
    Stack *temp = NULL;

    push(root, 1);
    push(root, 2);
    push(root, 3);
    push(root, 4);
    push(root, 5);

    for (i = 0; i < 6; i++) {
        temp = pop(root);
        if (temp) {
            printf("pop element: %d\n", temp->val);
        }
    }

    return 0;
}


void push(Stack *stack, int val)
{
    Stack *newnode = (Stack *)malloc(sizeof(Stack));
    newnode->val = val;
    newnode->next = NULL;

    newnode->next = stack->next;
    stack->next = newnode;
}

Stack *pop(Stack *stack)
{
    Stack *popnode = (Stack *)malloc(sizeof(Stack));
    popnode = top(stack);
    if (NULL == popnode) {
        printf("EMPTY STACK\n");
        return NULL;
    }
    Stack *temp = popnode;
    stack->next = temp->next;
    free(popnode);
    return temp;
}


Stack *top(Stack *stack)
{
    return stack->next;
}

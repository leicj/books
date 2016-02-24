// 后缀表达式
// 表达式存储于一个堆栈中.
// 先将中缀表达式转换为后缀表达式
// 然后通过堆栈计算其后缀表达式
// 操作符为字符串

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
// 打印堆栈
void print(Stack *stack);
// 中缀表达式转换为后缀表达式
Stack *mid2Postfix(Stack *stack);
// 计算后缀表达式
int calcpostfix(Stack *stack);
// 操作符的优先级: '(' > '*' >= '/' >= '+' >= '-'
int isLargeOpr(int opr1, int opr2);
// 判断是否为操作符
int isOpr(int c);
// 计算
int calc(int top1, int top2, int opr);
// 翻转堆栈
Stack *reverse(Stack *stack);

int main(void)
{
    int i = 0;
    Stack *root = (Stack *)malloc(sizeof(Stack));
    Stack *result = NULL;
    root->next = NULL;
    root->val = INT_MIN;
    Stack *temp = NULL;

    // 中缀表达式:6 * (5 + (2 + 3) * 8 + 3)
    push(root, ')');
    push(root, 3);
    push(root, '+');
    push(root, 8);
    push(root, '*');
    push(root, ')');
    push(root, 3);
    push(root, '+');
    push(root, 2);
    push(root, '(');
    push(root, '+');
    push(root, 5);
    push(root, '(');
    push(root, '*');
    push(root, 6);

    print(root->next);

    result = mid2Postfix(root);
    print(result);

    result = reverse(result);
    print(result);

    // 后缀表达式: 6 5 2 3 + 8 * + 3 + *

    printf("%d\n", calcpostfix(result));

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

void print(Stack *stack)
{
    while (stack) {
        if (0 <= stack->val && stack->val <= 9) {
            printf("%d ", stack->val);
        } else {
            printf("%c ", stack->val);
        }
        stack = stack->next;
    }
    printf("\n");
}

Stack *mid2Postfix(Stack *stack)
{
    Stack *opr = (Stack *)malloc(sizeof(Stack));
    Stack *result = (Stack *)malloc(sizeof(Stack));
    Stack *temp = NULL;
    Stack *tempOpr = NULL;
    int tempval = 0;
    opr->next = NULL;
    opr->val = INT_MIN;
    result->next = NULL;
    result->val = INT_MIN;

    while (stack && stack->next) {
        temp = pop(stack);
        tempval = temp->val;
        if (')' == tempval) {
            while (opr && opr->next->val != '(') {
                tempOpr = pop(opr);
                push(result, tempOpr->val);
            }
            // 弹出'('
            pop(opr);
        } else if (isOpr(tempval)) {
            while (opr && opr->next) {
                tempOpr = top(opr);
                if (isLargeOpr(tempOpr->val, tempval) && '(' != tempOpr->val) {
                    push(result, tempOpr->val);
                    pop(opr);
                } else {
                    push(opr, tempval);
                    break;
                }
            }
            if (NULL == opr->next) {
                push(opr, tempval);
            }
        } else {
            push(result, tempval);
        }
    }
    while (opr && opr->next) {
        tempOpr = pop(opr);
        push(result, tempOpr->val);
    }

    return result;
}

int calcpostfix(Stack *stack)
{
    Stack *result = (Stack *)malloc(sizeof(Stack));
    Stack *temp = NULL;
    Stack *top1 = NULL;
    Stack *top2 = NULL;

    while (stack && stack->next) {
        temp = pop(stack);
        if (isOpr(temp->val)) {
            top1 = pop(result);
            top2 = pop(result);
            push(result, calc(top1->val, top2->val, temp->val));
        } else {
            push(result, temp->val);
        }
    }
    temp = pop(result);
    return temp->val;
}

int isLargeOpr(int opr1, int opr2)
{
    if (opr1 == '(' && opr2 != '(') {
        return 1;
    }
    if (opr2 == '(') {
        return 0;
    }
    if (opr1 == '*' || opr1 == '/') {
        return 1;
    }
    if ((opr1 == '+' || opr1 == '-') && (opr2 == '+' || opr2 == '-')) {
        return 1;
    }

    return 0;
}

int isOpr(int c)
{
    if (c == '(' || c == '*' || c == '/' || c == '+' || c == '-') {
        return 1;
    }
    return 0;
}

int calc(int top1, int top2, int opr)
{
    int result = 0;
    switch (opr) {
        case '+':
            result = top1 + top2;
            break;
        case '-':
            result = top1 - top2;
            break;
        case '*':
            result = top1 * top2;
            break;
        case '/':
            if (0 != top2) {
                 result = top1 / top2;
            }
            break;
        default:
            break;
    }
    return result;
}

Stack *reverse(Stack *stack)
{
    Stack *result = (Stack *)malloc(sizeof(Stack));
    result->next = NULL;
    result->val = INT_MIN;
    stack = stack->next;
    while (stack) {
        push(result, stack->val);
        stack = stack->next;
    }

    return result;
}

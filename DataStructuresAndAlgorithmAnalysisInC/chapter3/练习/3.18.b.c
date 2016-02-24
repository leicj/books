// 检测C语言的平衡符号的程序
// /* */ () [] {}
// 使用堆栈实现
// 堆栈使用链表实现

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct NODE {
    struct NODE *next;
    int val;
} Node;

// 插入
void insert(Node *node, int val);
// 删除
void pop(Node *node);
// 得到首元素
int top(Node *node);
// 打印
void print(Node *node);

int main(void)
{
    int ch;
    int prevch;
    int tempch1;
    int tempch2;
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = INT_MIN;
    node->next = NULL;

    while ((ch = getchar()) != 'a') {
        if (ch == '(' || ch == '[' || ch == '{') {
            insert(node, ch);
            continue;
        }
        if (ch == '*' && prevch == '/') {
            insert(node, '/');
            insert(node, '*');
            continue;
        }

        if (ch == ')') {
            if (top(node) != '(') {
                printf("() not match!\n");
                return -1;
            }
            pop(node);
            continue;
        }
        if (ch == ']') {
            if (top(node) != '[') {
                printf("[] not match!\n");
                return -1;
            }
            pop(node);
            continue;
        }
        if (ch == '}') {
            if (top(node) != '{') {
                printf("{} not match!\n");
                return -1;
            }
            pop(node);
            continue;
        }
        if (ch == '/' && prevch == '*') {
            tempch1 = top(node);
            pop(node);
            tempch2 = top(node);
            pop(node);
            if (tempch1 != '*' || tempch2 != '/') {
                printf("/**/ not match!\n");
                return -1;
            }
            continue;
        }
        prevch = ch;
    }

    print(node->next);
    if (node && node->next) {
        printf("%c not match!\n", node->next->val);
        return -1;
    }

    return 0;
}


void insert(Node *node, int val)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->val = val;
    newnode->next = node->next;
    node->next = newnode;
}

void pop(Node *node)
{
    Node *delnode = node->next;
    node->next = delnode->next;
    free(delnode);
}

int top(Node *node)
{
    if (node && node->next) {
        return node->next->val;
    }

    return INT_MIN;
}

void print(Node *node)
{
    while (node) {
        printf("%c-->", node->val);
        node = node->next;
    }
    printf("NULL\n");
}

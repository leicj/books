// 编写查找一个单链表特定元素的程序.
// 分别使用递归和非递归方法实现
// 链表必须达到多大才使得递归的程序崩溃

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


typedef struct NODE {
    struct NODE *next;
    double val;
} Node;

// 插入
void insert(Node *node, double val);
// 递归查找
int recursive(Node *node, double val);
// 非递归查找
int find(Node *node, double val);
// 打印
void print(Node *node);

int main(void)
{
    Node *root = (Node *)malloc(sizeof(Node));
    root->next = NULL;
    root->val = INT_MIN;
    double i = 0;
    double N = 10000000;
    int result = 0;

    for (i = 0; i < N; i++) {
        insert(root, i);
    }

    result = find(root->next, N - 1);
    printf("%d\n", result);
    result = recursive(root->next, N - 1);
    printf("%d\n", result);

    return 0;
}

void insert(Node *node, double val)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->next = NULL;
    newnode->val = val;

    Node *prevnode = node;
    node = node->next;

    if (NULL == node) {
        prevnode->next = newnode;
        return;
    }

    while (node && node->val < val) {
        prevnode = node;
        node = node->next;
    }

    if (NULL == node) {
        prevnode->next = newnode;
    } else {
        prevnode->next = newnode;
        newnode->next = node;
    }
}


void print(Node *node)
{
    while (node) {
        printf("%f-->", node->val);
        node = node->next;
    }
    printf("NULL\n");
}

int recursive(Node *node, double val)
{
    if (node && node->val != val) {
        return recursive(node->next, val);
    } else {
        return node && 1;
    }
}

int find(Node *node, double val)
{
    while (node && node->val != val) {
        node = node->next;
    }
    return node && 1;
}

// 单链表的实现

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct NODE {
    struct NODE *next;
    int val;
} Node;

// 插入节点
void insert(Node *node, int val);
// 删除节点
void delete(Node *node, int val);
// 打印链表
void print(Node *node);

int main(void)
{
    Node *root = (Node *)malloc(sizeof(Node));
    root->next = NULL;
    root->val = INT_MIN;

    insert(root, 2);
    insert(root, 5);
    insert(root, 3);
    insert(root, 9);
    insert(root, 5);
    insert(root, 7);
    insert(root, 8);
    insert(root, 1);

    print(root->next);

    delete(root, 3);
    delete(root, 100);
    delete(root, 7);

    print(root->next);

    return 0;
}


void insert(Node *node, int val)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->next = NULL;
    newnode->val = val;

    Node *prevnode = node;
    node = node->next;

    // 为空链表
    if (NULL == node) {
        prevnode->next = newnode;
        return;
    }

    // 查找具体的位置
    while (node && node->val < val) {
         prevnode = node;
         node = node->next;
    }

    // 中间节点
    if (node) {
        prevnode->next = newnode;
        newnode->next = node;
    } else {
        prevnode->next = newnode;
    }
}

void print(Node *node)
{
    while (node) {
        printf("%d-->", node->val);
        node = node->next;
    }
    printf("NULL\n");
}


void delete(Node *node, int val)
{
    Node *prevnode = node;
    node = node->next;

    while (node && node->val < val) {
        prevnode = node;
        node = node->next;
    }

    if (node && node->val == val) {
        Node *temp = node;
        prevnode->next = node->next;
        free(temp);
    }
}

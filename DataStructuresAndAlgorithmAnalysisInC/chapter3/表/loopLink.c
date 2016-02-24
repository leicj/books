// 循环列表

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct NODE {
    struct NODE *prev;
    struct NODE *next;
    int val;
} Node;

// 插入
void insert(Node *node, int val);
// 删除
void delete(Node *node, int val);
// 打印
void print(Node *node);

int main(void)
{
    Node *root = (Node *)malloc(sizeof(Node));
    root->prev = root;
    root->next = root;
    root->val = INT_MIN;

    insert(root, 2);
    insert(root, 4);
    insert(root, 8);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);
    insert(root, 9);
    insert(root, 0);

    print(root->next);

    delete(root, 4);
    delete(root, 7);
    delete(root, 9);

    print(root->next);

    return 0;
}


void insert(Node *node, int val)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->prev = newnode->next = NULL;
    newnode->val = val;

    Node *prevnode = node;
    Node *root = node;
    node = node->next;

    if (NULL == node) {
        prevnode->next = newnode;
        newnode->prev = prevnode;
        newnode->next = root;
        root->prev = newnode;
        return;
    }

    while (node && node->val != INT_MIN && node->val < val) {
        prevnode = node;
        node = node->next;
    }

    if (node && node->val != INT_MIN) {
        prevnode->next = newnode;
        newnode->prev = prevnode;
        newnode->next = node;
        node->prev = newnode;
    } else {
        prevnode->next = newnode;
        newnode->prev = prevnode;
        newnode->next = root;
        root->prev = newnode;
    }
}


void print(Node *node)
{
    while (node && node->val != INT_MIN) {
        printf("%d-->", node->val);
        node = node->next;
    }
    printf("NULL\n");
}


void delete(Node *node, int val)
{
    Node *prevnode = node;
    node = node->next;

    while (node && node->val != INT_MIN && node->val < val) {
        prevnode = node;
        node = node->next;
    }

    if (node && node->val == val) {
        prevnode->next = node->next;
        node->next->prev = prevnode;
        free(node);
    }
}

// 双链表的实现

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct NODE {
    struct NODE *prev;
    struct NODE *next;
    int val;
} Node;

// 双向链表的新增
void insert(Node *node, int val);
// 双向链表的删除
void delete(Node *node, int val);
// 双向链表的打印
void print(Node *node);

int main(void)
{
    Node *root = (Node *)malloc(sizeof(Node));
    root->prev = root->next = NULL;
    root->val = INT_MIN;

    insert(root, 2);
    insert(root, 4);
    insert(root, 3);
    insert(root, 8);
    insert(root, 5);
    insert(root, 7);
    insert(root, 1);

    print(root->next);

    delete(root, 2);
    delete(root, 0);
    delete(root, 4);

    print(root->next);

    return 0;
}


void insert(Node *node, int val)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->prev = newnode->next = NULL;
    newnode->val = val;

    Node *prevnode = node;
    node = node->next;

    if (NULL == node) {
        prevnode->next = newnode;
        newnode->prev = prevnode;
        return;
    }

    while (node && node->val < val) {
        prevnode = node;
        node = node->next;
    }

    if (node) {
        prevnode->next = newnode;
        newnode->prev = prevnode;
        newnode->next = node;
        node->prev = newnode;
    } else {
        prevnode->next = newnode;
        newnode->prev = prevnode;
    }
}


void print(Node *node)
{
    while (node->next) {
        printf("%d-->", node->val);
        node = node->next;
    }
    printf("%d-->NULL", node->val);
    while (node->prev) {
        printf("<--%d", node->val);
        node = node->prev;
    }
    printf("\n");
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
        prevnode->next = node->next;
        node->next->prev = prevnode;
        free(node);
    }
}

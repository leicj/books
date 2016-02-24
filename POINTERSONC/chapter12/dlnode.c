// 双向链表的实现
// 支持插入/删除/打印

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct DLNODE {
    struct DLNODE *prev;
    struct DLNODE *next;
    int value;
} DLNode;

void insert(DLNode *node, int val);

void del(DLNode *node, int val);

void print(DLNode *node);

int main(void)
{
    DLNode *root = (DLNode *)malloc(sizeof(DLNode));
    root->prev = root->next = NULL;
    root->value = INT_MIN;

    insert(root, 4);
    printf("%d--%d\n", root->value, root->next->value);
    insert(root, 2);
    insert(root, 5);
    insert(root, 8);
    insert(root, 3);
    insert(root, 6);
    insert(root, 4);
    insert(root, 3);

    print(root->next);

    del(root, 3);
    del(root, 2);
    del(root, 8);
    del(root, 1);

    print(root->next);

    return 0;
}

void insert(DLNode *node, int val)
{
    DLNode *newnode = (DLNode *)malloc(sizeof(DLNode));
    newnode->prev = newnode->next = NULL;
    newnode->value = val;
    DLNode *prevnode = node;
    node = node->next;

    if (NULL == node) {
        prevnode->next = newnode;
        newnode->prev = prevnode;
        return;
    }

    while (node && node->value < val) {
        prevnode = node;
        node = node->next;
    }
    prevnode->next = newnode;
    newnode->prev = prevnode;
    if (node) {
        newnode->next = node;
        node->prev = newnode;
    }
}


void print(DLNode *node)
{
    DLNode *prevnode = node;
    printf("prev-->next:");
    while (node) {
        printf("%d-->", node->value);
        prevnode = node;
        node = node->next;
    }
    printf("NULL\n");

    printf("next-->prev:NULL<--");
    while (prevnode->value != INT_MIN) {
        printf("%d<--", prevnode->value);
        prevnode = prevnode->prev;
    }
    printf("\n");
}


void del(DLNode *node, int val)
{
    node = node->next;
    while (node && node->value < val) {
        node = node->next;
    }
    if (node->value == val) {
        if (node->next) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        } else {
            node->prev->next = NULL;
        }
    }
}

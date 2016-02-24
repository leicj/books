// 自调整表的链表实现.
// 自调整表如同一个规则表.但是所有的插入都在表头进行,当一个元素被Find访问时,它就被移到表头而并不改变其余的项的相对顺序.
// 表头为链表的第一个元素

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct NODE {
    struct NODE *next;
    int val;
} Node;

// 插入
void insert(Node *node, int val);
// 查询
void Find(Node *node, int val);
// 打印
void print(Node *node);

int main(void)
{
    Node *root = (Node *)malloc(sizeof(Node));
    root->next = NULL;
    root->val = INT_MIN;

    insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);
    print(root->next);

    Find(root, 2);
    print(root->next);
    Find(root, 3);
    print(root->next);
    Find(root, 4);
    print(root->next);
    Find(root, 5);
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

    prevnode->next = newnode;
    newnode->next = node;
}

void Find(Node *node, int val)
{
    Node *root = node;
    Node *head = root->next;
    Node *prev = node;
    node = node->next;

    while (node && node->val != val) {
        prev = node;
        node = node->next;
    }
    if (node->val == val) {
        Node *temp = (Node *)malloc(sizeof(Node));
        temp = node->next;
        root->next = node;
        if (prev == head) {
            node->next = head;
        } else {
            node->next = head->next;
            prev->next = head;
        }
        head->next = temp;
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

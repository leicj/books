// 使用链表实现删除重复元素

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct NODE {
    struct NODE *next;
    int val;
} Node;

// 删除重复元素
void delete(Node *node)
{
    Node *curNode = node;
    Node *prevNode = NULL;
    Node *nextNode = NULL;

    while (curNode) {
        prevNode = curNode;
        nextNode = curNode->next;
        while (nextNode) {
            if (curNode->val == nextNode->val) {
                prevNode->next = nextNode->next;
                nextNode = prevNode->next;
            } else {
                prevNode = nextNode;
                nextNode = nextNode->next;
            }
        }
        curNode = curNode->next;
    }
}

// 打印链表
void print(Node *node)
{
    while (node) {
        printf("%d-->", node->val);
        node = node->next;
    }
    printf("NULL\n");
}

int main(void)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    node->val = INT_MIN;

    Node n1, n2, n3, n4, n5, n6;
    node->next = &n1;
    n1.val = 1;
    n2.val = 2;
    n3.val = 5;
    n4.val = 2;
    n5.val = 1;
    n6.val = 6;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = NULL;

    print(node->next);

    delete(node->next);
    print(node->next);

    return 0;
}

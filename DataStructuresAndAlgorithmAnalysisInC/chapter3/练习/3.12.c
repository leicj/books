// 编写一个非递归过程以O(N)时间反转单链表

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct NODE {
    struct NODE *next;
    int val;
} Node;

// 反转链表
Node *reverse(Node *node)
{
    Node *currentNode = (Node *)malloc(sizeof(Node));
    Node *nextNode = NULL;
    if (node && node->next) {
        nextNode = node->next;
        currentNode->val = node->val;
        currentNode->next = NULL;
    }
    while (node && nextNode) {
        node = nextNode;
        nextNode = nextNode->next;
        node->next = currentNode;
        currentNode = node;
    }

    return node;
}

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
    Node l1, l2, l3;
    Node *reverseNode = NULL;
    l1.val = 1;
    l2.val = 2;
    l3.val = 3;
    l1.next = &l2;
    l2.next = &l3;
    l3.next = NULL;

    print(&l1);

    reverseNode = reverse(&l1);
    print(reverseNode);

    return 0;
}

// 问题描述
// N个人从1~N编号,围坐成一圈.从1号开始传递热土豆,经过M次传递后拿着热土豆的人被清除离座
// ,由坐在被清除的人的后面的人拿起热土豆继续传递.
// 求解清除的顺序编号
// 使用循环链表

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct NODE {
    struct NODE *prev;
    struct NODE *next;
    int val;
} Node;

// 插入链表
void insert(Node *node, int val);
// 打印
void print(Node *node);

int main(void)
{
    Node *root = (Node *)malloc(sizeof(Node));
    Node *deleteNode = NULL;
    Node *prevnode = NULL;
    Node *nextnode = NULL;
    Node *winner = NULL;
    root->prev = root;
    root->next = root;
    root->val = INT_MIN;
    int i = 0;
    int M = 1;
    int N = 5;
    int time = N - 1;
    int count;

    for (i = 0; i < N; i++) {
        insert(root, i + 1);
    }

    print(root->next);

    prevnode = root->prev;
    nextnode = root->next->next;
    deleteNode = root->next;
    prevnode->next = deleteNode;
    deleteNode->prev = prevnode;
    free(root);

    while (time > 0) {
       count = M;
       while (count > 0) {
           prevnode = deleteNode;
           deleteNode = nextnode;
           nextnode = deleteNode->next;
           count -= 1;
       }
       printf("%d ", deleteNode->val);
       Node *temp = deleteNode;
       prevnode->next = nextnode;
       nextnode->prev = prevnode;
       free(temp);
       deleteNode = nextnode;
       nextnode = deleteNode->next;
       winner = deleteNode;
       time -= 1;
    }
    printf("\nthe last winner is:%d\n", winner->val);
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


    while (node && node->val != INT_MIN) {
        prevnode = node;
        node = node->next;
    }
    prevnode->next = newnode;
    newnode->prev = prevnode;
    newnode->next = root;
    root->prev = newnode;
}

void print(Node *node)
{
    while (node && node->val != INT_MIN) {
        printf("%d-->", node->val);
        node = node->next;
    }
    printf("NULL\n");
}

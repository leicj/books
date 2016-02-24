// 计算2^4000,进行问题的延伸,求计算两个大数相乘
// 如M * N,对于计算机肯定会溢出,那么如何进行相乘保证可以合理得到结果?
// 通过链表来存储计算即可
// 假设M = 12345678, 则链表为8-->7-->6-->5-->4-->3-->2-->1-->NULL
// N = 11223344, 则链表为4-->4-->3-->3-->2-->2-->1-->1-->1-->NULL
// 则M * N = 138559791107232(一般会溢出,所以才用链表表示),则链表为2-->3-->2-->7-->0-->1-->1-->9-->7-->9-->5-->5-->8-->3-->1-->NULL

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct NODE {
    struct NODE *next;
    int val;
} Node;

// 插入
void insert(Node *node, int val);
// 相乘
Node *mul(Node *node1, Node *node2);
// 相乘子函数
Node *submul(Node *node, int val);
// 两个链表相加
Node *subadd(Node *node1, Node *node2);
// 打印
void print(Node *node);

int main(void)
{
    int M = 12345678;
    int N = 11223344;
    Node *nodeM = (Node *)malloc(sizeof(Node));
    Node *nodeN = (Node *)malloc(sizeof(Node));
    Node *tempNode = NULL;
    nodeM->next = NULL;
    nodeM->val = INT_MIN;
    nodeN->next = NULL;
    nodeN->val = INT_MIN;

    while (M / 10) {
        insert(nodeM, M % 10);
        M = M / 10;
    }
    insert(nodeM, M);

    while (N / 10) {
        insert(nodeN, N % 10);
        N = N / 10;
    }
    insert(nodeN, N);

    print(nodeM->next);
    print(nodeN->next);

    tempNode = mul(nodeM->next, nodeN->next);
    print(tempNode->next);

    return 0;
}

void insert(Node *node, int val)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->next = NULL;
    newnode->val = val;

    while (node && node->next) {
        node = node->next;
    }

    node->next = newnode;
}

Node *subadd(Node *node1, Node *node2)
{
    Node *resultNode = (Node *)malloc(sizeof(Node));
    resultNode->next = NULL;
    resultNode->val = INT_MIN;
    int result = 0;
    int sum = 0;
    int upval = 0;

    while (node1 && node2) {
        result = node1->val + node2->val;
        sum = result % 10 + upval;
        upval = result / 10 + sum / 10;
        sum = sum % 10;
        insert(resultNode, sum);
        node1 = node1->next;
        node2 = node2->next;
    }
    while (node1) {
        sum = node1->val;
        if (upval) {
            sum = node1->val + upval;
            if (sum > 9) {
                sum = sum % 10;
                upval = sum / 10;
            }
        }
        insert(resultNode, sum);
        node1 = node1->next;
    }
    while (node2) {
        sum = node2->val;
        if (upval) {
            sum = node2->val + upval;
            if (sum > 9) {
                sum = sum % 10;
                upval = sum / 10;
            }
        }
        insert(resultNode, sum);
        node2 = node2->next;
    }
    return resultNode;
}

Node *submul(Node *node, int val)
{
    Node *resultNode = (Node *)malloc(sizeof(Node));
    resultNode->next = NULL;
    resultNode->val = INT_MIN;
    int upval = 0; //进阶数
    int result = 0; //相乘的结果
    int remainder = 0;

    while (node) {
        result = node->val * val;
        remainder = result % 10 + upval;
        upval = result / 10 + remainder / 10;
        remainder = remainder % 10;
        insert(resultNode, remainder);
        node = node->next;
    }
    return resultNode;
}

Node *mul(Node *node1, Node *node2)
{
    Node *resultNode = NULL;
    Node *curNode = NULL;
    int node2val = 0;
    int number = 0;
    int tempNum = 0;

    while (node2) {
        number++;
        node2val = node2->val;
        if (NULL == resultNode) {
            resultNode = submul(node1, node2val);
        } else {
            curNode = submul(node1, node2val);
            tempNum = number;
            while (--tempNum) {
                Node *zeroNode = (Node *)malloc(sizeof(Node));
                zeroNode->val = 0;
                zeroNode->next = curNode->next;
                curNode->next = zeroNode;
            }
            resultNode = subadd(resultNode->next, curNode->next);
            curNode = NULL;
        }
        node2 = node2->next;
    }
    return resultNode;
}

void print(Node *node)
{
    while (node) {
        printf("%d-->", node->val);
        node = node->next;
    }
    printf("NULL\n");
}

// 懒惰删除法
// 删除一个元素时,只是给此节点增加一个删除标志.
// 如果删除的元素和未删除的元素节点一样多,则执行删除操作

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct NODE {
    struct NODE *next;
    int num; //记录链表中未删除的节点个数
    int delnum; //记录链表中已删除节点的个数
    int isdel; //判断是否已被删除
    int val;
} Node;

// 删除
void del(Node *node, int val);
// 打印
void print(Node *node);

int main(void)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    node->val = INT_MIN;
    node->num = node->delnum = 0;
    node->num = 7;
    node->delnum = 0;

    Node n1, n2, n3, n4, n5, n6, n7;
    n1.val = 1;
    n2.val = 2;
    n3.val = 3;
    n4.val = 4;
    n5.val = 5;
    n6.val = 6;
    n7.val = 7;
    node->next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    n7.next = NULL;
    n1.isdel = 0;
    n2.isdel = 0;
    n3.isdel = 0;
    n4.isdel = 0;
    n5.isdel = 0;
    n6.isdel = 0;
    n7.isdel = 0;

    del(node, 2);
    del(node, 4);
    print(node->next);
    del(node, 5);
    del(node, 6);
    print(node->next);

    return 0;
}

void del(Node *node, int val)
{
    Node *root = node;
    Node *prevnode = node;
    node = node->next;

    while (node && node->val != val) {
        node = node->next;
    }
    if (node->val == val) {
        node->isdel = 1;
        root->num = root->num - 1;
        root->delnum = root->delnum + 1;
    }

    if (root->num <= root->delnum) {
        root->delnum = 0;
        node = root->next;
        while (node) {
            if (node->isdel) {
                prevnode->next = node->next;
                node = prevnode->next;
            } else {
                prevnode = node;
                node = node->next;
            }
        }
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

// 只通过调节指针而非数据,交换两个相邻的元素
// 使用单链表完成
// 如1-->2-->3-->4,则交换后变成2-->3-->4-->1

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct LINK {
    struct LINK *next;
    int val;
} Link;

void swapLink(Link *link)
{
    Link *prevlink = link;
    Link *nextlink = NULL;
    link = link->next;
    while (link && link->next) {
        nextlink = link->next;
        prevlink->next = nextlink;
        link->next = link->next->next;
        nextlink->next = link;
        prevlink = prevlink->next;
    }
}

void print(Link *link)
{
    while (link) {
        printf("%d-->", link->val);
        link = link->next;
    }
    printf("NULL\n");
}

int main(void)
{
    Link *root = (Link *)malloc(sizeof(Link));
    Link l1, l2, l3, l4, l5;
    root->val = INT_MIN;
    root->next = &l1;
    l1.val = 1;
    l2.val = 2;
    l3.val = 3;
    l4.val = 4;
    l5.val = 5;
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    l5.next = NULL;

    swapLink(root);

    print(root->next);

    return 0;
}


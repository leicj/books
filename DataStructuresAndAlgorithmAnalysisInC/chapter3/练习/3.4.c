// 求两个链表的交集

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct LINK {
    struct LINK *next;
    int val;
} Link;

void insert(Link *link, int val)
{
    Link *newlink = (Link *)malloc(sizeof(Link));
    newlink->next = NULL;
    newlink->val = val;

    while (link->next) {
        link = link->next;
    }
    link->next = newlink;
}
Link *merge(Link *l1, Link *l2)
{
    Link *root = (Link *)malloc(sizeof(Link));
    root->next = NULL;
    root->val = INT_MIN;

    l1 = l1->next;
    l2 = l2->next;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            l1 = l1->next;
        } else if (l2->val < l1->val) {
            l2 = l2->next;
        } else {
            insert(root, l1->val);
            l1 = l1->next;
            l2 = l2->next;
        }
    }

    return root;
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
    Link *link1 = (Link *)malloc(sizeof(Link));
    Link *link2= (Link *)malloc(sizeof(Link));
    Link *link = NULL;
    Link l1, l2, l3, l4, l5, l6, l7;
    l1.val = 1;
    l2.val = 2;
    l3.val = 3;
    l4.val = 4;
    l5.val = 0;
    l6.val = 2;
    l7.val = 4;

    link1->next = &l1;
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = NULL;

    link2->next = &l5;
    l5.next = &l6;
    l6.next = &l7;
    l7.next = NULL;

    link = merge(link1, link2);
    print(link->next);

    return 0;
}

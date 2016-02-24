// 编写函数printLots(L, P)
// L是链表, P指定哪些位置的元素要打印
// 如P = {1,3,4,6},这这些位置上的元素打印出来
// 如果超出链表,则打印NULL

#include <stdio.h>
#include <stdlib.h>

typedef struct LINK {
    struct LINK *next;
    int val;
} Link;

void printLots(Link *link, int P[], int len)
{
    int index = 1;
    int i = 0;
    for (i = 0; i < len && link; i++) {
        while (index != P[i] && link) {
            index++;
            link = link->next;
        }
        if (NULL == link) {
            break;
        }
        if (P[i] == index) {
            printf("%d-->", link->val);
        }
        link = link->next;
        index++;
    }
    for (; i < len; i++) {
        printf("NULL-->");
    }
    printf("NULL\n");
}

int main(void)
{
    Link *l1 = (Link *)malloc(sizeof(Link));
    Link l2, l3, l4, l5, l6, l7, l8;
    int P[] = {1, 3, 4, 6, 10};
    int len = 5;
    l1->val = 1;
    l2.val = 2;
    l3.val = 3;
    l4.val = 4;
    l5.val = 5;
    l6.val = 6;
    l7.val = 7;
    l8.val = 8;
    l1->next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    l5.next = &l6;
    l6.next = &l7;
    l7.next = &l8;
    l8.next = NULL;

    printLots(l1, P, len);

    return 0;
}

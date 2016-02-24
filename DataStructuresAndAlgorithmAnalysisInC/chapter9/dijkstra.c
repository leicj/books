// 拓扑排序
// 找出任意一个没有入边的顶点,然后显示出该顶点,并将它和它的边一起从图中删除.
// 然后,我们对图的其余部分应用同样的方法处理

#include <stdio.h>
#include <limits.h>

typedef struct LINK {
    int val;
    struct LINK *next;
    int d;//权
} Link;

typedef struct HASHLINK {
    Link *link;
    struct HASHLINK *next;
    int d;//路径长度
    int known; //是否已被找到
    struct HASHLINK *prev;// 前一个节点
} Hashlink;

void dijkstra(Hashlink *root, Hashlink *hashlink);

void print(Hashlink *hashlink);

int main(void)
{
    Hashlink root, v1, v2, v3, v4, v5, v6, v7;
    root.next = &v1;
    v1.next = &v2;
    v2.next = &v3;
    v3.next = &v4;
    v4.next = &v5;
    v5.next = &v6;
    v6.next = &v7;
    v7.next = NULL;
    v1.known = v2.known = v3.known = v4.known = v5.known = v6.known = v7.known = 0;
    v1.d = v2.d = v3.d = v4.d = v5.d = v6.d = v7.d = INT_MAX;

    Link v1_1, v1_2, v1_4, v2_2, v2_4, v2_5, v3_3, v3_1, v3_6, v4_4, v4_3, v4_5, v4_6, v4_7, v5_5, v5_7, v6_6, v7_7, v7_6;
    v1_1.val = v3_1.val = 1;
    v1_2.val = v2_2.val = 2;
    v3_3.val = v4_3.val = 3;
    v1_4.val = v2_4.val = v4_4.val = 4;
    v2_5.val = v4_5.val = v5_5.val = 5;
    v3_6.val = v4_6.val = v6_6.val = v7_6.val = 6;
    v4_7.val = v5_7.val = v7_7.val = 7;
    v1.link = &v1_1;
    v1_1.next = &v1_2;
    v1_2.next = &v1_4;
    v1_4.next = NULL;
    v2.link = &v2_2;
    v2_2.next = &v2_4;
    v2_4.next = &v2_5;
    v2_5.next = NULL;
    v3.link = &v3_3;
    v3_3.next = &v3_1;
    v3_1.next = &v3_6;
    v3_6.next = NULL;
    v4.link = &v4_4;
    v4_4.next = &v4_3;
    v4_3.next = &v4_5;
    v4_5.next = &v4_6;
    v4_6.next = &v4_7;
    v4_7.next = NULL;
    v5.link = &v5_5;
    v5_5.next = &v5_7;
    v5_7.next = NULL;
    v6.link = &v6_6;
    v6_6.next = NULL;
    v7.link = &v7_7;
    v7_7.next = &v7_6;
    v7_6.next = NULL;

    v1_2.d = 2;
    v1_4.d = 1;
    v2_4.d = 3;
    v2_5.d = 10;
    v3_1.d = 4;
    v3_6.d = 5;
    v4_3.d = 2;
    v4_5.d = 2;
    v4_6.d = 8;
    v4_7.d = 4;
    v5_7.d = 6;
    v7_6.d = 1;

    v1.prev = NULL;
    v1.d = 0;
    v1.known = 1;
    dijkstra(&root, &v1);

    print(&v2);
    printf("\n");
    print(&v3);
    printf("\n");
    print(&v4);
    printf("\n");
    print(&v5);
    printf("\n");
    print(&v6);
    printf("\n");
    print(&v7);
    printf("\n");

    return 0;
}

void dijkstra(Hashlink *root, Hashlink *hashlink)
{
    Link *link = hashlink->link->next;
    while (link) {
        Hashlink *temp = root->next;
        while (temp) {
            if (temp->link->val == link->val && link->d + hashlink->d < temp->d) {
                temp->d = hashlink->d + link->d;
                temp->prev = hashlink;
                temp->known = 1;
                break;
            }
            temp = temp->next;
        }
        link = link->next;
    }
    link = hashlink->link->next;
    while (link) {
        Hashlink *temp = root->next;
        while (temp) {
            if (temp->link->val == link->val && temp->d == link->d + hashlink->d) {
                dijkstra(root, temp);
                break;
            }
            temp = temp->next;
        }
        link = link->next;
    }
}

void print(Hashlink *hashlink)
{
    if (hashlink) {
        print(hashlink->prev);
        printf("%d-->", hashlink->link->val);
    }
}

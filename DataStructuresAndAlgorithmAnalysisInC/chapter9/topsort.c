// 拓扑排序
// 找出任意一个没有入边的顶点,然后显示出该顶点,并将它和它的边一起从图中删除.
// 然后,我们对图的其余部分应用同样的方法处理

#include <stdio.h>

typedef struct LINK {
    int val;
    struct LINK *next;
} Link;

typedef struct HASHLINK {
    Link *link;
    struct HASHLINK *next;
    int num;//入度
} Hashlink;

// 获取入度为0的节点
Hashlink *getDegreeZero(Hashlink *hashlink);
// topsort
void topsort(Hashlink *hashlink);

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

    Link v1_1, v1_2, v1_3, v1_4, v2_2, v2_4, v2_5, v3_3, v3_6, v4_4, v4_3, v4_6, v4_7, v5_5, v5_4, v5_7, v6_6, v7_7, v7_6;
    v1_1.val = 1;
    v1_2.val = v2_2.val = 2;
    v1_3.val = v3_3.val = v4_3.val = 3;
    v1_4.val = v2_4.val = v4_4.val = v5_4.val = 4;
    v2_5.val = v5_5.val = 5;
    v3_6.val = v4_6.val = v6_6.val = v7_6.val = 6;
    v4_7.val = v5_7.val = v7_7.val = 7;
    v1.link = &v1_1;
    v1.num = 0;
    v1_1.next = &v1_2;
    v1_2.next = &v1_3;
    v1_3.next = &v1_4;
    v1_4.next = NULL;
    v2.link = &v2_2;
    v2.num = 1;
    v2_2.next = &v2_4;
    v2_4.next = &v2_5;
    v2_5.next = NULL;
    v3.link = &v3_3;
    v3.num = 2;
    v3_3.next = &v3_6;
    v3_6.next = NULL;
    v4.link = &v4_4;
    v4.num = 3;
    v4_4.next = &v4_3;
    v4_3.next = &v4_6;
    v4_6.next = &v4_7;
    v4_7.next = NULL;
    v5.link = &v5_5;
    v5.num = 1;
    v5_5.next = &v5_4;
    v5_4.next = &v5_7;
    v5_7.next = NULL;
    v6.link = &v6_6;
    v6.num = 3;
    v6_6.next = NULL;
    v7.link = &v7_7;
    v7.num = 2;
    v7_7.next = &v7_6;
    v7_6.next = NULL;

    topsort(&root);

    return 0;
}
// 获取入度为0的节点
Hashlink *getDegreeZero(Hashlink *hashlink)
{
    Hashlink *root = hashlink;
    Hashlink *prev = root;
    hashlink = hashlink->next;

    while (hashlink) {
        if (hashlink->num == 0) {
            Link *link = hashlink->link;
            link = link->next;
            while (link) {
                Hashlink *temp = root->next;
                while (temp) {
                    if (temp->link->val == link->val) {
                        temp->num -= 1;
                        break;
                    } else {
                        temp = temp->next;
                    }
                }
                link = link->next;
            }
            return prev;
        }
        prev = hashlink;
        hashlink = hashlink->next;
    }
    return NULL;
}
// topsort
void topsort(Hashlink *hashlink)
{
    Hashlink *root = hashlink;
    Hashlink *prev = root;

    while (root->next) {
        prev = getDegreeZero(root);
        if (NULL == prev) {
            return;
        }
        printf("%d ", prev->next->link->val);
        prev->next = prev->next->next;
    }

}

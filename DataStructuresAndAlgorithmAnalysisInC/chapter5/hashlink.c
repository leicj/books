// 分离链接法
// 散列表的大小为10(一般情况下最好取值为素数)

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 10

typedef struct HASH{
    int val;
    struct HASH *next;
} Hash;

typedef struct HASHLINK {
    int index;
    struct HASHLINK *next;
    Hash *hash;
} Hashlink;

// 插入
void insert(Hashlink *hashlink, int val);
// 删除
void delete(Hashlink *hashlink, int val);
// 查找(判断此值是否在哈希表中)
int find(Hashlink *hashlink, int val);
// 打印散列表
void print(Hashlink *hashlink);

int main(void)
{
    int arr[] = {0, 1, 81, 4, 64, 25, 16, 36, 9, 49};
    Hashlink *root = (Hashlink *)malloc(sizeof(Hashlink));
    root->index = INT_MIN;
    root->next = NULL;
    root->hash = NULL;
    Hashlink *prevlink = root;
    int i = 0;
    for (i = 0; i < SIZE; i++) {
        Hashlink *newlink = (Hashlink *)malloc(sizeof(Hashlink));
        newlink->index = i;
        newlink->next = NULL;
        newlink->hash = NULL;
        prevlink->next = newlink;
        prevlink = newlink;
    }

    for (i = 0; i < 10; i++) {
        insert(root->next, arr[i]);
    }
    print(root->next);

    delete(root->next, 4);
    delete(root->next, 36);
    print(root->next);

    if (find(root->next, 49)) {
        printf("we find 49!\n");
    } else {
        printf("we cannot find 49\n");
    }
    if (find(root->next, 36)) {
        printf("we find 36\n");
    } else {
        printf("we cannot find 36\n");
    }

    return 0;

}
// 插入
void insert(Hashlink *hashlink, int val)
{
    int index = val % SIZE;
    while (index != hashlink->index) {
        hashlink = hashlink->next;
    }
    Hash *newhash = (Hash *)malloc(sizeof(Hash));
    newhash->val = val;
    newhash->next = NULL;

    if (NULL == hashlink->hash) {
        hashlink->hash = newhash;
    } else {
        newhash->next = hashlink->hash;
        hashlink->hash = newhash;
    }
}
// 删除
void delete(Hashlink *hashlink, int val)
{
    int index = val % SIZE;
    while (index != hashlink->index) {
        hashlink = hashlink->next;
    }
    Hash *hash = hashlink->hash;
    Hash *prevhash = hash;

    while (val != hash->val) {
        prevhash = hash;
        hash = hash->next;
    }
    if (NULL != hash) {
        if (hash != hashlink->hash) {
            prevhash->next = hash->next;
            free(hash);
        } else {
            hashlink->hash = hash->next;
            free(hash);
        }
    }
}
// 查找(判断此值是否在哈希表中)
int find(Hashlink *hashlink, int val)
{
    int index = val % SIZE;
    while (index != hashlink->index) {
        hashlink = hashlink->next;
    }
    Hash *hash = hashlink->hash;
    while (NULL != hash && val != hash->val) {
        hash = hash->next;
    }

    return NULL != hash;
}
// 打印散列表
void print(Hashlink *hashlink)
{
    while (NULL != hashlink) {
        printf("%d:", hashlink->index);
        Hash *hash = hashlink->hash;
        while (NULL != hash) {
            printf("%d-->", hash->val);
            hash = hash->next;
        }
        printf("NULL\n");
        hashlink = hashlink->next;
    }
}

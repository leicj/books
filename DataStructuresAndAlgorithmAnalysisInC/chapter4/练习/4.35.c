// 层序遍历
// 主要思想为: 先打印根节点,然后将根的孩子节点存入一个链表中.
// 接着遍历链表,打印其孩子节点.并且将其孩子的孩子节点存入链表中

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct TREE {
    struct TREE *left;
    struct TREE *right;
    int val;
} Tree;

typedef struct LINK {
    struct LINK *next;
    Tree *tree;
} Link;

// 插入
void insert(Tree *tree, int val);
// levelorder
void levelorder(Tree *tree);
// midorder
void midorder(Tree *tree);
// insertlink
void insertlink(Link *link, Tree *tree);

int main(void)
{
    Tree *root = (Tree *)malloc(sizeof(Tree));
    root->left = root->right = NULL;
    root->val = INT_MIN;

    insert(root, 5);
    insert(root, 3);
    insert(root, 2);
    insert(root, 1);
    insert(root, 4);
    insert(root, 8);
    insert(root, 7);
    insert(root, 6);
    insert(root, 9);

    printf("mid order is:");
    midorder(root->left);
    printf("\n");

    printf("level order is:");
    levelorder(root->left);
    printf("\n");

    return 0;
}
// 插入
void insert(Tree *tree, int val)
{
    Tree *newnode = (Tree *)malloc(sizeof(Tree));
    newnode->left = newnode->right = NULL;
    newnode->val = val;

    Tree *root = tree;
    Tree *prevnode = root;
    tree = tree->left;

    if (NULL == tree) {
        prevnode->left = newnode;
        return;
    }
    while (tree) {
        prevnode = tree;
        if (tree->val < val) {
            tree = tree->right;
        } else if (tree->val > val) {
            tree = tree->left;
        } else {
            return;
        }
    }

    if (prevnode->val > val) {
        prevnode->left = newnode;
    } else {
        prevnode->right = newnode;
    }
}
// levelorder
void levelorder(Tree *tree)
{
    Link *link = (Link *)malloc(sizeof(Link));
    link->next = NULL;
    link->tree = tree;
    while (link) {
        printf("%d ", link->tree->val);
        if (link->tree->left) {
            insertlink(link, link->tree->left);
        }
        if (link->tree->right) {
            insertlink(link, link->tree->right);
        }
        link = link->next;
    }
}
// insertlink
void insertlink(Link *link, Tree *tree)
{
    Link *newlink = (Link *)malloc(sizeof(Link));
    newlink->tree = tree;
    newlink->next = NULL;

    while (link->next) {
        link = link->next;
    }
    link->next = newlink;
}
// midorder
void midorder(Tree *tree)
{
    if (tree) {
        printf("%d ", tree->val);
        midorder(tree->left);
        midorder(tree->right);
    }
}


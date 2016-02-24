// 只通过指向二叉树根的指针,求:
// 树中节点的个数
// 树中树叶的个数
// 树中满节点的个数

// 1. 递归树进行计算
// 2. 递归树,判断节点为叶子时候,返回1即可
// 3. 计算树的深度,执行函数2^N + 1即可

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

typedef struct TREE {
    struct TREE *left;
    struct TREE *right;
    int val;
} Tree;

// 插入节点
void insert(Tree *tree, int val);
// 中序遍历
void midorder(Tree *tree);
// 节点的个数
int nodenum(Tree *tree);
// 树叶的个数
int leftnum(Tree *tree);
// 满节点的个数
int totalnodenum(Tree *tree);
// 树的深度
int len(Tree *tree);
// max
int max(int a, int b);
int main(void)
{
    Tree *root = (Tree *)malloc(sizeof(Tree));
    root->left = root->right = NULL;
    root->val = INT_MIN;

    insert(root, 10);
    insert(root, 4);
    insert(root, 2);
    insert(root, 1);
    insert(root, 3);
    insert(root, 6);
    insert(root, 5);
    insert(root, 8);
    insert(root, 7);
    insert(root, 9);
    insert(root, 11);
    insert(root, 12);
    insert(root, 13);
    insert(root, 14);

    midorder(root->left);
    printf("\n");

    printf("node num:%d\n", nodenum(root->left));
    printf("left num:%d\n", leftnum(root->left));
    printf("total node num:%d\n", totalnodenum(root->left));
    printf("len is:%d\n", len(root->left));

    return 0;
}
// 插入节点
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

    if (prevnode->val < val) {
        prevnode->right = newnode;
    } else {
        prevnode->left = newnode;
    }
}
// 中序遍历
void midorder(Tree *tree)
{
    if (tree) {
        midorder(tree->left);
        printf("%d ", tree->val);
        midorder(tree->right);
    }
}
// 节点的个数
int nodenum(Tree *tree)
{
    if (NULL == tree) {
        return 0;
    }
    if (NULL == tree->left && NULL == tree->right) {
        return 1;
    }
    return nodenum(tree->left) + nodenum(tree->right) + 1;
}
// 树叶的个数
int leftnum(Tree *tree)
{
    if (NULL == tree) {
        return 0;
    }
    if (NULL == tree->left && NULL == tree->right) {
        return 1;
    }
    return leftnum(tree->left) + leftnum(tree->right);
}
// 满节点的个数
int totalnodenum(Tree *tree)
{
    int treelen = len(tree);
    return pow(2.0, treelen) - 1;
}
// 树的深度
int len(Tree *tree)
{
    if (NULL == tree) {
        return 0;
    }
    if (NULL == tree->left && NULL == tree->right) {
        return 1;
    }
    return max(len(tree->left), len(tree->right)) + 1;
}
// max
int max(int a, int b)
{
    if (a > b) {
        return a;
    }
    return b;
}

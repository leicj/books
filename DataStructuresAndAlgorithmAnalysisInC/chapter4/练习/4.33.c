// 给树的每个节点添加(x, y)
// 坐标x可以通过中序遍历来计算
// 坐标y可以通过节点深度的相反数算出

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct TREE {
    struct TREE *left;
    struct TREE *right;
    int x;
    int y;
    int val;
} Tree;

// 插入
void insert(Tree *tree, int val);
// 中序遍历
void midorder(Tree *tree, int x, int treelen);
// 树的深度
int len(Tree *tree, int y);
// max
int max(int a, int b);
// pow
int mypow(int x, int n);

int main(void)
{
    Tree *root = (Tree *)malloc(sizeof(Tree));
    root->left = root->right = NULL;
    root->val = INT_MIN;
    int x = 0;
    int y = 0;
    int treelen = 0;

    insert(root, 5);
    insert(root, 3);
    insert(root, 2);
    insert(root, 4);
    insert(root, 1);
    insert(root, 8);
    insert(root, 7);
    insert(root, 9);
    insert(root, 6);

    treelen = len(root->left, y);
    x = mypow(2, treelen) / 2;
    y = mypow(2, treelen) / 2;
    len(root->left, y);
    midorder(root->left, x, treelen);
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
// 中序遍历
void midorder(Tree *tree, int x, int treelen)
{
    if (tree) {
        tree->x = x;
        printf("(%d:{%d:%d})", tree->val, tree->x, tree->y);
        midorder(tree->left, x - treelen, treelen / 2);
        midorder(tree->right, x + treelen, treelen / 2);
    }
}
// 树的深度
int len(Tree *tree, int y)
{
    if (NULL == tree) {
        return 0;
    }
    if (NULL == tree->left && NULL == tree->right) {
        return 1;
    }
    tree->y = y;
    return max(len(tree->left, y / 2), len(tree->right, y / 2)) + 1;
}
// max
int max(int a, int b)
{
    if (a > b) {
        return a;
    }

    return b;
}
// pow
int mypow(int x, int n)
{
    int sum = 1;
    while (n--) {
        sum *= x;
    }

    return sum;
}

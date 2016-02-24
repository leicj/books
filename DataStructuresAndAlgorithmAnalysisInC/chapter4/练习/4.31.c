// 构建理想平衡二叉树

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

typedef struct TREE {
    struct TREE *left;
    struct TREE *right;
    int val;
} Tree;

// Fib
int Fib(int n)
{
    if (0 == n) {
        return 0;
    }
    if (1 == n) {
        return 1;
    }
    return Fib(n - 1) + Fib(n - 2) + 1;
}

Tree *generateTree(int n, int nums)
{
    Tree *newnode = (Tree *)malloc(sizeof(Tree));
    newnode->left = newnode->right = NULL;
    newnode->val = nums;
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->left = tree->right = NULL;
    tree->val = nums;

    if (1 == n) {
        return newnode;
    } else {
        tree->left = generateTree(n - 1, nums - Fib(n - 1));
        tree->right = generateTree(n - 1, nums + Fib(n - 1));
        return tree;
    }
}

void preorder(Tree *tree)
{
    if (tree) {
        printf("%d ", tree->val);
        preorder(tree->left);
        preorder(tree->right);
    }
}

int main(void)
{
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->left = tree->right = NULL;
    tree->val = INT_MIN;

    int n = 4;
    int nums = (pow(2.0, n) + 1) / 2;
    tree->left = generateTree(n, nums);

    preorder(tree->left);
    printf("\n");

    return 0;
}

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

void preorder(Tree *tree, int k1, int k2)
{
    if (tree) {
        if (k1 <= tree->val && tree->val <= k2) {
            printf("%d ", tree->val);
            preorder(tree->left, k1, k2);
            preorder(tree->right, k1, k2);
        }
        else if (tree->right && (k1 <= tree->right->val && tree->right->val <= k2)) {
            preorder(tree->right, k1, k2);
        }
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

    preorder(tree->left, 6, 14);
    printf("\n");

    return 0;
}

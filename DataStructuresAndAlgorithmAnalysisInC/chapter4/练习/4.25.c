// 伸展树的实现

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct TREE {
    struct TREE *left;
    struct TREE *right;
    struct TREE *parent;
    int val;
} Tree;

// 插入
void insert(Tree *tree, int val);
// 左-右旋转
Tree *doubleRotateLeft(Tree *tree);
// 左单旋转
Tree *singleRotateLeft(Tree *tree);
// 右-左旋转
Tree *doubleRotateRight(Tree *tree);
// 右单旋转
Tree *singleRotateRight(Tree *tree);
// 前序遍历
void preorder(Tree *tree);
// 查找节点
void find(Tree *tree, int val);
// 计算路径
int len(Tree *tree);
// max
int max(int a, int b);
int main(void)
{
    Tree *root = (Tree *)malloc(sizeof(Tree));
    root->left = root->right = root->parent = NULL;
    root->val = INT_MIN;
    int i = 0;
    int minlen = INT_MAX;
    int templen = 0;

    for (i = 1024; i >= 1; i--) {
        insert(root, i);
    }
    preorder(root->left);
    printf("\n");

    for (i = 1; i <= 20; i++) {
        find(root, i);
        templen = len(root->left);
        if (templen < minlen) {
            minlen = templen;
        }
        printf("(%d: len %d)\n", i, len(root->left));
      //  preorder(root->left);
        printf("\n");
    }
    printf("min len is:%d\n", minlen);

    return 0;
}
// 插入
void insert(Tree *tree, int val)
{
    Tree *newnode = (Tree *)malloc(sizeof(Tree));
    newnode->left = newnode->right = newnode->parent = NULL;
    newnode->val = val;
    Tree *root = tree;
    Tree *prevnode = root;
    tree = tree->left;

    if (NULL == tree) {
        root->left = newnode;
        newnode->parent = root;
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
        newnode->parent = prevnode;
    } else {
        prevnode->right = newnode;
        newnode->parent = prevnode;
    }
}
// 左-右旋转
Tree *doubleRotateLeft(Tree *tree)
{
    tree->left = singleRotateRight(tree->left);

    return singleRotateLeft(tree);
}
// 左单旋转
Tree *singleRotateLeft(Tree *tree)
{
    Tree *lefttree = tree->left;
    tree->left = lefttree->right;
    if (lefttree->right) {
        lefttree->right->parent = tree;
    }
    lefttree->right = tree;
    lefttree->parent = tree->parent;
    tree->parent = lefttree;
    if (lefttree->parent->left == tree) {
        lefttree->parent->left = lefttree;
    } else {
        lefttree->parent->right = lefttree;
    }

    return lefttree;
}
// 右-左旋转
Tree *singleRotateRight(Tree *tree)
{
    Tree *righttree = tree->right;
    tree->right = righttree->left;
    if (righttree->left) {
        righttree->left->parent = tree;
    }
    righttree->left = tree;
    righttree->parent = tree->parent;
    tree->parent = righttree;
    if (righttree->parent->left == tree) {
        righttree->parent->left = righttree;
    } else {
        righttree->parent->right = righttree;
    }

    return righttree;
}
// 右单旋转
Tree *doubleRotateRight(Tree *tree)
{
    tree->right = singleRotateLeft(tree->right);

    return singleRotateRight(tree);
}
// 前序遍历
void preorder(Tree *tree)
{
    if (tree) {
        printf("%d ", tree->val);
        preorder(tree->left);
        preorder(tree->right);
    }
}
// 查找节点
void find(Tree *tree, int val)
{
    Tree *root = tree;
    Tree *parentnode = NULL;
    Tree *grandnode = NULL;
    tree = tree->left;

    while (tree) {
        if (tree->val == val) {
            break;
        } else if (tree->val > val) {
            tree = tree->left;
        } else {
            tree = tree->right;
        }
    }

    if (tree && tree->val == val) {
        parentnode = tree->parent;
        while (parentnode->val != INT_MIN) {
            grandnode = parentnode->parent;
            if (grandnode->val == INT_MIN) {
                if (parentnode->left == tree) {
                    singleRotateLeft(parentnode);
                } else {
                    singleRotateRight(parentnode);
                }
                return;
            } else {
                if (grandnode->left == parentnode && parentnode->left == tree) {
                    singleRotateLeft(grandnode);
                    singleRotateLeft(parentnode);
                } else if (grandnode->left == parentnode && parentnode->right == tree) {
                    doubleRotateLeft(grandnode);
                } else if (grandnode->right == parentnode && parentnode->right == tree) {
                    singleRotateRight(grandnode);
                    singleRotateRight(parentnode);
                } else if (grandnode->right == parentnode && parentnode->left == tree) {
                    doubleRotateRight(grandnode);
                }
                parentnode = tree->parent;
            }
        }
    }
}

// 计算路径
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

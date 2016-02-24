// 二叉搜索树的实现
// 不允许存在重复的元素

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
// 删除
void delete(Tree *tree, int val);
// 复制节点
void transnode(Tree *node1, Tree *node2);
// 最小右孩子
Tree *minRightChild(Tree *tree);
// 中序遍历
void midorder(Tree *tree);

int main(void)
{
    Tree *root = (Tree *)malloc(sizeof(Tree));
    root->left = root->right = root->parent = NULL;
    root->val = INT_MIN;

    insert(root, 5);
    insert(root, 3);
    insert(root, 8);
    insert(root, 2);
    insert(root, 4);
    insert(root, 1);
    insert(root, 6);
    insert(root, 7);
    insert(root, 9);

    midorder(root->left);
    printf("\n");

    delete(root, 3);
    midorder(root->left);
    printf("\n");
    delete(root, 8);
    midorder(root->left);
    printf("\n");
    delete(root, 5);
    midorder(root->left);
    printf("\n");

    return 0;
}


// 插入
void insert(Tree *tree, int val)
{
    Tree *root = tree;
    tree = tree->left;
    Tree *parent = NULL;
    Tree *newnode = (Tree *)malloc(sizeof(Tree));
    newnode->left = newnode->right = newnode->parent = NULL;
    newnode->val = val;

    if (NULL == tree) {
        root->left = newnode;
        newnode->parent = root;
        return;
    }

    while (tree) {
        parent = tree;
        if (tree->val < val) {
            tree = tree->right;
        } else if (tree->val > val) {
            tree = tree->left;
        } else {
            return;
        }
    }

    if (parent->val < val) {
        parent->right = newnode;
        newnode->parent = parent;
    } else {
        parent->left = newnode;
        newnode->parent = parent;
    }
}
// 删除
void delete(Tree *tree, int val)
{
    Tree *root = tree;
    tree = tree->left;

    while (tree) {
        if (tree->val < val) {
            tree = tree->right;
        } else if (tree->val > val) {
            tree = tree->left;
        } else {
            break;
        }
    }

    if (tree->val == val) {
        // 如果左孩子为空
        if (NULL == tree->left) {
            transnode(tree, tree->right);
        } else if (NULL == tree->right) {
            transnode(tree, tree->left);
        } else {
            Tree *rightNum = minRightChild(tree->right);
            if (rightNum->parent == tree) {
                transnode(tree, rightNum);
                rightNum->left = tree->left;
                tree->left->parent = rightNum;
            } else {
                rightNum->parent->left = rightNum->right;
                rightNum->right->parent = rightNum->parent;
                tree->val = rightNum->val;
            }
        }
    }
}

// 复制节点
void transnode(Tree *node1, Tree *node2)
{
    if (node1->parent->left == node1) {
        node1->parent->left = node2;
    } else {
        node1->parent->right = node2;
    }
    node2->parent = node1->parent;
}
// 最小右孩子
Tree *minRightChild(Tree *tree)
{
    while (tree->left) {
        tree = tree->left;
    }
    return tree;
}
// 中序遍历
void midorder(Tree *tree)
{
    if (tree) {
        midorder(tree->left);
        printf("%d  ", tree->val);
        midorder(tree->right);
    }
}

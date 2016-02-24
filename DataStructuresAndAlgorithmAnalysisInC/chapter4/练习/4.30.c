// AVL树的实现
// 在拥有Fib情况下,不知道如何构建一棵最小的AVL树

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

typedef struct TREE {
    struct TREE *left;
    struct TREE *right;
    struct TREE *parent;
    int height;
    int val;
} Tree;

// 插入
void insert(Tree *tree, int val);
// 删除
void delete(Tree *tree, int val);
// 中序遍历
void midorder(Tree *tree);
// 前序遍历
void preorder(Tree *tree);
// 左单旋转
Tree *singleRotateWithLeft(Tree *tree);
// 右单旋转
Tree *singleRotateWithRight(Tree *tree);
// 左双旋转
Tree *doubleRotateWithLeft(Tree *tree);
// 右双旋转
Tree *doubleRotateWithRight(Tree *tree);
// max
int max(int a, int b);
// Height
int Height(Tree *tree);
// transnode
void transnode(Tree *tree, Tree *newnode);
// treeMinimum
Tree *treeMinimum(Tree *tree);
// treeMaximum
Tree *treeMaximum(Tree *tree);
// Fib
int Fib(int n);
// len
int len(Tree *tree);

int main(void)
{
    Tree *root = (Tree *)malloc(sizeof(Tree));
    root->left = root->right = root->parent = NULL;
    root->height = -1;
    root->val = INT_MIN;
    int i = 0;
    for (i = 0; i <= 10; i++) {
        printf("Fib(%d):%d\n", i, Fib(i));
    }

    int nums = Fib(10);
    printf("nums is:%d\n", nums);
    for (i = 0; i < nums; i++) {
        insert(root, i);
    }

    midorder(root->left);
    printf("\n");
    printf("len is:%d\n", len(root->left));

    return 0;
}

// 插入
void insert(Tree *tree, int val)
{
    Tree *newnode = (Tree *)malloc(sizeof(Tree));
    newnode->left = newnode->right = newnode->parent = NULL;
    newnode->val = val;
    newnode->height = 1;
    Tree *root = tree;
    tree = tree->left;
    Tree *prevnode = root;

    if (NULL == tree) {
        root->left = newnode;
        newnode->parent = root;
        return;
    }
    while (tree) {
        prevnode = tree;
        tree->height += 1;
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

    // 判断是否违反AVL性质
    while (prevnode->val != INT_MIN) {
        if (abs(Height(prevnode->left) - Height(prevnode->right)) != 2) {
            prevnode = prevnode->parent;
            prevnode->height = max(Height(prevnode->left), Height(prevnode->right)) + 1;
        } else {
            if (Height(prevnode->left) - Height(prevnode->right) == 2) {
                if (prevnode->left->val > val) {
                    singleRotateWithLeft(prevnode);
                } else {
                    doubleRotateWithLeft(prevnode);
                }
            } else {
                if (prevnode->right->val < val) {
                    singleRotateWithRight(prevnode);
                } else {
                    doubleRotateWithRight(prevnode);
                }
            }
            prevnode = prevnode->parent;
        }
    }

}
// 删除
void delete(Tree *tree, int val)
{
    Tree *root = tree;
    Tree *prevnode = root;
    tree = tree->left;

    while (tree) {
        prevnode = tree;
        if (tree->val < val) {
            tree = tree->right;
        } else if (tree->val > val) {
            tree = tree->left;
        } else {
            break;
        }
    }

    if (tree->val == val) {
        Tree *tempnode = tree->parent;
        prevnode = tree->parent;
        if (NULL == tree->left) {
            transnode(tree, tree->right);
        } else if (NULL == tree->right) {
            transnode(tree, tree->left);
        } else {
            Tree *delnode = treeMinimum(tree->right);
            // 调整height
            tempnode = delnode->parent;
            prevnode = delnode->parent;
            if (delnode->parent != tree) {
                transnode(delnode, delnode->right);
                delnode->right = tree->right;
                delnode->right->parent = delnode;
            }
            transnode(tree, delnode);
            delnode->left = tree->left;
            delnode->left->parent = delnode;
            delnode->height = tree->height;
        }
        printf("%d??\n", tempnode->val);
        while (tempnode->parent->val != INT_MIN) {
            tempnode->height = max(Height(tempnode->left), Height(tempnode->right)) + 1;
            tempnode = tempnode->parent;
        }
        // 判断是否违反AVL性质
        while (prevnode->val != INT_MIN) {
            if (abs(Height(prevnode->left) - Height(prevnode->right)) != 2) {
                prevnode = prevnode->parent;
                prevnode->height = max(Height(prevnode->left), Height(prevnode->right)) + 1;
            } else {
                if (Height(prevnode->left) - Height(prevnode->right) == 2) {
                    if (prevnode->left->val > val) {
                        singleRotateWithLeft(prevnode);
                    } else {
                        doubleRotateWithLeft(prevnode);
                    }
                } else {
                    if (prevnode->right->val < val) {
                        singleRotateWithRight(prevnode);
                    } else {
                        doubleRotateWithRight(prevnode);
                    }
                }
                prevnode = prevnode->parent;
            }
        }
        // 找到最大节点数,再次进行AVL性质的判断(解决连续删除两个节点才导致违反AVL性质的情况)
        prevnode = treeMaximum(root->left);
        // 判断是否违反AVL性质
        while (prevnode->val != INT_MIN) {
            if (abs(Height(prevnode->left) - Height(prevnode->right)) != 2) {
                prevnode = prevnode->parent;
                prevnode->height = max(Height(prevnode->left), Height(prevnode->right)) + 1;
            } else {
                if (Height(prevnode->left) - Height(prevnode->right) == 2) {
                    if (prevnode->left->val > val) {
                        singleRotateWithLeft(prevnode);
                    } else {
                        doubleRotateWithLeft(prevnode);
                    }
                } else {
                    if (prevnode->right->val < val) {
                        singleRotateWithRight(prevnode);
                    } else {
                        doubleRotateWithRight(prevnode);
                    }
                }
                prevnode = prevnode->parent;
            }
        }
    }
}
// transnode
void transnode(Tree *tree, Tree *newnode)
{
    if (tree == tree->parent->left) {
        tree->parent->left = newnode;
    } else {
        tree->parent->right = newnode;
    }
    if (newnode != NULL) {
        newnode->parent = tree->parent;
    }
}
// rightSmallNum
Tree *treeMinimum(Tree *tree)
{
    while (tree->left) {
        tree = tree->left;
    }
    return tree;
}
// treeMaximum
Tree *treeMaximum(Tree *tree)
{
    while (tree->right) {
        tree = tree->right;
    }
    return tree;
}
// 中序遍历
void midorder(Tree *tree)
{
    if (tree) {
        midorder(tree->left);
        printf("(%d : %d) ", tree->val, tree->height);
        midorder(tree->right);
    }
}
// 前序遍历
void preorder(Tree *tree)
{
    if (tree) {
        printf("(%d : %d) ", tree->val, tree->height);
        preorder(tree->left);
        preorder(tree->right);
    }
}
// 左单旋转
Tree *singleRotateWithLeft(Tree *tree)
{
    Tree *lefttree = tree->left;
    tree->left = lefttree->right;
    if (lefttree->right) {
        lefttree->right->parent = tree;
    }
    lefttree->right = tree;
    lefttree->parent = tree->parent;
    tree->parent = lefttree;
    tree->height = max(Height(tree->left), Height(tree->right)) + 1;
    lefttree->height = max(Height(lefttree->left), Height(lefttree->right)) + 1;
    if (lefttree->parent->left == tree) {
        lefttree->parent->left = lefttree;
    } else {
        lefttree->parent->right = lefttree;
    }

    return lefttree;
}
// 右单旋转
Tree *singleRotateWithRight(Tree *tree)
{
    Tree *righttree = tree->right;
    tree->right = righttree->left;
    if (righttree->left) {
        righttree->left->parent = tree;
    }
    righttree->left = tree;
    righttree->parent = tree->parent;
    tree->parent = righttree;
    tree->height = max(Height(tree->left), Height(tree->right)) + 1;
    righttree->height = max(Height(righttree->left), Height(righttree->right)) + 1;
    if (righttree->parent->left == tree) {
        righttree->parent->left = righttree;
    } else {
        righttree->parent->right = righttree;
    }

    return righttree;
}
// 左双旋转
Tree *doubleRotateWithLeft(Tree *tree)
{
    tree->left = singleRotateWithRight(tree->left);

    return singleRotateWithLeft(tree);
}
// 右双旋转
Tree *doubleRotateWithRight(Tree *tree)
{
    tree->right = singleRotateWithLeft(tree->right);

    return singleRotateWithRight(tree);
}
int max(int a, int b)
{
    if (a > b) {
        return a;
    }
    return b;
}

int Height(Tree *tree)
{
    if (NULL == tree) {
        return 0;
    }
    return tree->height;
}
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
// len
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

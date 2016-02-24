#include <iostream>
#include <string>
using namespace std;

class TreeNode{
    friend void show(TreeNode *rhs);
public:
    TreeNode(const string &s = string()) :
        value(s), count(0), left(0), right(0){}
    TreeNode(const TreeNode &rhs) :
        left(new TreeNode(*rhs.left)),
        right(new TreeNode(*rhs.right)),
        value(rhs.value),
        count(rhs.count){}
    TreeNode &operator=(const TreeNode &rhs)
    {
        left = new TreeNode(*rhs.left);
        right = new TreeNode(*rhs.right);
        value = rhs.value;
        count = rhs.count;
        return *this;
    }
    ~TreeNode()
    {
        if (left) {
            delete left;
        }
        if (right) {
            delete right;
        }
    }
    void setleft(TreeNode &node)
    {
        delete left;
        left = new TreeNode();
        left->value = node.value;
    }
    void setright(TreeNode &node)
    {
        delete right;
        right = new TreeNode();
        right->value = node.value;
    }
    string getvalue()
    {
        return value;
    }
private:
    string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};
void show(TreeNode *node)
{
    if (node) {
        cout << node->value << " ";
        if (node->left) show(node->left);
        if (node->right) show(node->right);
    }
}

int main(void)
{
    TreeNode node1("hello");
    TreeNode node2("world");
    TreeNode node3("what?");

    node1.setleft(node2);
    node1.setright(node3);

    show(&node1);

    return 0;
}

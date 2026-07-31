#include <bits/stdc++.h>
using namespace std;

class BinaryTreeNode
{
public:
    int val;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

BinaryTreeNode *input_tree()
{
    int val;
    cin >> val;
    BinaryTreeNode *root;
    if (val == -1)
        root = NULL;
    else
        root = new BinaryTreeNode(val);

    queue<BinaryTreeNode *> q;
    if (root)
    {
        q.push(root);
    }

    while (!q.empty())
    {
        BinaryTreeNode *p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        BinaryTreeNode *leftNode, *rightNode;
        if (l == -1)
            leftNode = NULL;
        else
            leftNode = new BinaryTreeNode(l);

        if (r == -1)
            rightNode = NULL;
        else
            rightNode = new BinaryTreeNode(r);

        p->left = leftNode;
        p->right = rightNode;

        if (p->left)
        {
            q.push(p->left);
        }
        if (p->right)
        {
            q.push(p->right);
        }
    }

    return root;
};

bool is_node_present(BinaryTreeNode *root, int x)
{
    queue<BinaryTreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        BinaryTreeNode *p = q.front();
        q.pop();

        if (p->val == x)
        {
            return true;
        }

        if (p->left)
        {
            q.push(p->left);
        }

        if (p->right)
        {
            q.push(p->right);
        }
    }

    return false;
}

int main()
{

    BinaryTreeNode *root = input_tree();

    int target;
    cin >> target;

    cout << is_node_present(root, target) << endl;

    return 0;
}
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

int mx;
int max_height(BinaryTreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    int l = max_height(root->left);
    int r = max_height(root->right);
    int d = l + r;
    mx = max(mx, d);

    return max(l, r) + 1;
};

int main()
{
    mx = 0;

    BinaryTreeNode *root = input_tree();
    int h = max_height(root);

    cout << mx << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *input_tree()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);

    queue<Node *> q;
    if (root)
    {
        q.push(root);
    }

    while (!q.empty())
    {
        Node *parent = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        Node *leftNode, *rightNode;
        if (l == -1)
            leftNode = NULL;
        else
            leftNode = new Node(l);

        if (r == -1)
            rightNode = NULL;
        else
            rightNode = new Node(r);

        parent->left = leftNode;
        parent->right = rightNode;

        if (parent->left)
        {
            q.push(parent->left);
        }

        if (parent->right)
        {
            q.push(parent->right);
        }
    }

    return root;
};

int sum_of_tree_without_leaf(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 0;
    }

    int l = sum_of_tree_without_leaf(root->left);
    int r = sum_of_tree_without_leaf(root->right);

    return root->val + l + r;
}

int main()
{
    Node *root = input_tree();

    int ans = sum_of_tree_without_leaf(root);

    cout << ans << endl;

    return 0;
}
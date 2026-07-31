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

void collect_leaf_node_val(Node *root, vector<int> &leaf)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        leaf.push_back(root->val);
        return;
    }

    collect_leaf_node_val(root->left, leaf);
    collect_leaf_node_val(root->right, leaf);
}

int main()
{
    Node *root = input_tree();

    vector<int> leaf;

    collect_leaf_node_val(root, leaf);

    sort(leaf.begin(), leaf.end(), greater<int>());

    for (int x : leaf)
    {
        cout << x << " ";
    }

    return 0;
}
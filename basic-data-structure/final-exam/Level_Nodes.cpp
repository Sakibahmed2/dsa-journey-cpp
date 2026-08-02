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

int get_level(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int l = get_level(root->left);
    int r = get_level(root->right);

    return max(l, r) + 1;
}

vector<int> get_level_nodes(Node *root, int val)
{
    queue<pair<Node *, int>> q;
    if (root)
    {
        q.push({root, 0});
    }

    vector<int> ans;

    while (!q.empty())
    {
        pair<Node *, int> parent = q.front();
        q.pop();

        Node *n = parent.first;
        int l = parent.second;

        if (val == l)
        {
            ans.push_back(n->val);
        }

        if (n->left)
        {
            q.push({n->left, l + 1});
        }
        if (n->right)
        {
            q.push({n->right, l + 1});
        }
    }

    return ans;
};

int main()
{

    Node *root = input_tree();

    int val;
    cin >> val;

    int level = get_level(root);

    if (val >= level)
    {
        cout << "Invalid" << endl;
        return 0;
    }

    vector<int> ans = get_level_nodes(root, val);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}
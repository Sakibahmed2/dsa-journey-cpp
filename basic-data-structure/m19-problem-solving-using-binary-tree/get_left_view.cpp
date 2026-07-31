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

vector<int> get_left_view(BinaryTreeNode *root)
{
    queue<pair<BinaryTreeNode *, int>> q;
    if (root)
    {
        q.push({root, 1});
    }

    vector<int> ans;
    int freq[3005] = {false};

    while (!q.empty())
    {
        pair<BinaryTreeNode *, int> parent = q.front();
        q.pop();

        BinaryTreeNode *node = parent.first;
        int level = parent.second;

        if (!freq[level])
        {
            ans.push_back(node->val);
            freq[level] = true;
        }

        if (node->left)
        {
            q.push({node->left, level + 1});
        }

        if (node->right)
        {
            q.push({node->right, level + 1});
        }
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        BinaryTreeNode *root = input_tree();

        vector<int> ans = get_left_view(root);

        for (int x : ans)
        {
            cout << x << " ";
        }

        cout << endl;
    }

    return 0;
}
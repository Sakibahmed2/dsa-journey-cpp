#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode *input_tree()
{
    int val;
    cin >> val;

    TreeNode *root;
    if (val == -1)
        root = NULL;
    else
        root = new TreeNode(val);

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        TreeNode *myLeft, *myRight;
        if (l == -1)
            myLeft = NULL;
        else
            myLeft = new TreeNode(l);

        if (r == -1)
            myRight = NULL;
        else
            myRight = new TreeNode(r);

        p->left = myLeft;
        p->right = myRight;

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

int sumOfLeftLeaves(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int sum = 0;

    if (root->left != nullptr)
    {
        // Check if left child is a leaf
        if (root->left->left == nullptr && root->left->right == nullptr)
        {
            sum += root->left->val;
        }
        else
        {
            sum += sumOfLeftLeaves(root->left);
        }
    }

    sum += sumOfLeftLeaves(root->right);

    return sum;
}

int main()
{

    TreeNode *root = input_tree();

    int ans = sumOfLeftLeaves(root);

    cout << ans << endl;

    return 0;
}
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
        q.push(root);

    while (!q.empty())
    {
        // 1. Ber kore ana
        Node *p = q.front();
        q.pop();

        // 2. Oi node niyee kaj koraa
        int l, r;
        cin >> l >> r;
        Node *myLeft, *myRight;
        if (l == -1)
            myLeft = NULL;
        else
            myLeft = new Node(l);

        if (r == -1)
            myRight = NULL;
        else
            myRight = new Node(r);

        p->left = myLeft;
        p->right = myRight;

        // 3. Push children
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }

    return root;
};

// Count usin level order
int cnt_node(Node *root)
{
    int cnt = 0;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        // 1. Ber kore anaa
        Node *f = q.front();
        q.pop();

        // 2. Oi node niyee kaj
        cnt++;

        // 3. children push
        if (f->left)
        {
            q.push(f->left);
        }
        if (f->right)
        {
            q.push(f->right);
        }
    }

    return cnt;
}

// Count using recursion
int cnt_node_recursion(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int l = cnt_node_recursion(root->left);
    int r = cnt_node_recursion(root->right);

    return l + r + 1;
}

int main()
{

    Node *root = input_tree();

    // int ans = cnt_node(root);
    int ans = cnt_node_recursion(root);

    cout << ans << endl;

    return 0;
}
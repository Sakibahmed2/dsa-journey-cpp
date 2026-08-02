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
}

void getLeftView(Node *root, vector<int> &left_nodes)
{
    if (root == NULL)
    {
        return;
    }

    left_nodes.push_back(root->val);

    if (root->left)
    {
        getLeftView(root->left, left_nodes);
    }
    else if (root->right)
    {
        getLeftView(root->right, left_nodes);
    }
}

void getRightView(Node *root, vector<int> &right_nodes)
{
    if (root == NULL)
    {
        return;
    }

    right_nodes.push_back(root->val);

    if (root->right)
    {
        getRightView(root->right, right_nodes);
    }
    else if (root->left)
    {
        getRightView(root->left, right_nodes);
    }
}

int main()
{
    Node *root = input_tree();
    if (root == NULL)
    {
        return 0;
    }

    vector<int> left_nodes;
    vector<int> right_nodes;

    if (root->left)
    {
        getLeftView(root->left, left_nodes);
    }

    if (root->right)
    {
        getRightView(root->right, right_nodes);
    }

    for (int i = left_nodes.size() - 1; i >= 0; i--)
    {
        cout << left_nodes[i] << " ";
    }

    cout << root->val << " ";

    for (int i = 0; i < right_nodes.size(); i++)
    {
        cout << right_nodes[i] << " ";
    }

    return 0;
}

// Theoretical Question Explanation:

// Question Analysis:
// আমাকে একটি Binary Tree ইনপুট হিসেবে দেওয়া হবে।
// আমার কাজ হলো tree-এর outer boundary print করা।
// Output শুরু হবে left-most leaf node থেকে এবং শেষ হবে right-most leaf node পর্যন্ত।
// এজন্য tree এর left side এবং right side আলাদা করে collect করতে হবে।
// তারপর left side reverse করে print করতে হবে, এরপর root print করতে হবে,
// এবং সবশেষে right side normal order-এ print করতে হবে।

// Observation:
// Left boundary collect করার সময় সবসময় left child কে priority দিতে হবে।
// যদি left child না থাকে, তাহলে right child দিয়ে নিচে নামতে হবে।
// একইভাবে right boundary collect করার সময় right child-কে priority দিতে হবে।
// যদি right child না থাকে, তাহলে left child দিয়ে continue করতে হবে।
// Left boundary vector-এ store করার পর reverse order-এ print করতে হবে,
// কারণ output left-most leaf node থেকে শুরু হবে।
// Root আলাদা করে print করতে হবে এবং শেষে right boundary normal order-এ print করতে হবে।

// Testcase Analysis:

// Example Tree:

//          10
//        /    \
//      20      30
//     /          \
//    40          50
//   /              \
// 90               60

// Left Boundary Collect:
// 20 -> 40 -> 90

// Reverse Print:
// 90 40 20

// Root:
// 10

// Right Boundary Collect:
// 30 -> 50 -> 60

// Final Output:
// 90 40 20 10 30 50 60
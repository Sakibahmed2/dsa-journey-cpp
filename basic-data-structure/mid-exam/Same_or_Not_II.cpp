#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        this->next = NULL;
    }
};

class myStack
{
public:
    Node *head = NULL;
    int sz = 0;

    void push(int val)
    {
        sz++;
        Node *newNode = new Node(val);

        newNode->next = head;
        head = newNode;
    }

    void pop()
    {
        sz--;
        if (head == NULL)
        {
            return;
        }

        Node *deleteNode = head;
        head = head->next;

        delete deleteNode;
    }

    int top()
    {
        return head->value;
    }

    int size()
    {
        return sz;
    }

    bool empty()
    {
        return head == NULL;
    }
};

class myQueue
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;

    void push(int val)
    {
        sz++;
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void pop()
    {
        sz--;
        Node *deleteNode = head;
        head = head->next;

        delete deleteNode;

        if (head == NULL)
        {
            tail = NULL;
        }
    }

    int front()
    {
        return head->value;
    }

    int size()
    {
        return sz;
    }

    bool empty()
    {
        return head == NULL;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    myStack st;
    myQueue qu;
    if (n != m)
    {
        cout << "NO" << endl;
        return 0;
    }
    int val;
    while (n--)
    {
        cin >> val;
        st.push(val);
    }
    while (m--)
    {
        cin >> val;
        qu.push(val);
    }
    while (!st.empty() && !qu.empty())
    {
        if (st.top() != qu.front())
        {
            cout << "NO" << endl;
            return 0;
        }
        st.pop();
        qu.pop();
    }
    cout << "YES" << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *prev;

    Node(int value)
    {
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

class myQueue
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;

    void push(int val) // O(1)
    {
        sz++;
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
            return;
        }
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }

    void pop() // O(1)
    {
        sz--;
        Node *deletenode = head;
        head = head->next;
        delete deletenode;
        if (head == NULL)
        {
            tail = NULL;
            return;
        }
        head->prev = NULL;
    }

    int front() // O(1)
    {
        return head->value;
    }

    int back() // O(1)
    {
        return tail->value;
    }

    int size() // O(1)
    {
        return sz;
    }

    bool empty() // O(1)
    {
        return head == NULL;
    }
};

int main()
{
    myQueue qu;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        qu.push(val);
    }

    while (!qu.empty())
    {
        cout << qu.front() << " ";
        qu.pop();
    }

    return 0;
}
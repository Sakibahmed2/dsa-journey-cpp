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

void insert_at_head(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head->prev = newnode;

    head = newnode;
}

void insert_at_tail(Node *&head, Node *&tail, int val)
{
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

void insert_at_any_position(Node *&head, Node *&tail, int idx, int val)
{
    Node *newnode = new Node(val);
    Node *temp = head;
    for (int i = 1; i < idx; i++)
    {
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;
}

void print_forword(Node *head)
{
    Node *temp = head;
    cout << "L -> ";
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }

    cout << endl;
}

void print_backword(Node *tail)
{
    Node *temp = tail;
    cout << "R -> ";
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    Node *head = NULL;
    Node *tail = NULL;

    int sz = 0;

    while (t--)
    {
        int idx, val;
        cin >> idx >> val;

        if (idx == 0)
        {
            insert_at_head(head, tail, val);
            sz++;
        }
        else if (idx == sz)
        {
            sz++;
            insert_at_tail(head, tail, val);
        }
        else if (idx > sz)
        {
            cout << "Invalid" << endl;
            continue;
        }
        else
        {
            sz++;
            insert_at_any_position(head, tail, idx, val);
        }

        print_forword(head);
        print_backword(tail);
    }

    return 0;
}
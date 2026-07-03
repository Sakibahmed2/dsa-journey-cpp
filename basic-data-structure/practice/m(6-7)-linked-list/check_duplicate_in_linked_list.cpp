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

void print_linked_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << endl;
        temp = temp->next;
    }
};

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
    tail = newnode;
};

void check_duplicate(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        Node *index = temp->next;

        while (index != NULL)
        {
            if (index->value == temp->value)
            {
                cout << "YES" << endl;
                return;
            }
            index = index->next;
        }
        temp = temp->next;
    }
    cout << "NO" << endl;
};

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int t;
    cin >> t;

    while (t--)
    {
        int x;
        cin >> x;
        insert_at_tail(head, tail, x);
    }

    check_duplicate(head);

    return 0;
}
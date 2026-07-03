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

void count_size(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    cout << "Size of the list: " << count;
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

void insert_at_head(Node *&head, int val)
{
    Node *newnode = new Node(val);
    newnode->next = head;
    head = newnode;
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

void insert_at_any_position(Node *&head, int idx, int val)
{
    Node *newnode = new Node(val);
    Node *temp = head;
    for (int i = 0; i < idx; i++)
    {
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
};

int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *tail = new Node(40);

    head->next = a;
    a->next = b;
    b->next = tail;

    insert_at_head(head, 50);
    insert_at_tail(head, tail, 100);
    insert_at_any_position(head, 2, 200);
    print_linked_list(head);
    // count_size(head);

    return 0;
}
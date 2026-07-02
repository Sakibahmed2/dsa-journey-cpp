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
}

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = tail->next;
};

void delete_at_any_position(Node *head, int idx)
{
    Node *temp = head;
    for (int i = 1; i < idx; i++)
    {
        temp = temp->next;
    }

    Node *deletenode = temp->next;
    temp->next = deletenode->next;

    delete deletenode;
};

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int n;
    while (true)
    {
        cin >> n;
        if (n == -1)
        {
            break;
        }
        insert_at_tail(head, tail, n);
    }

    delete_at_any_position(head, 1);
    print_linked_list(head);

    return 0;
}
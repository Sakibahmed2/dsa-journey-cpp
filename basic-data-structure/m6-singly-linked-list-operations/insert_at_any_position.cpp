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

void insert_at_any_position(Node *&head, int idx, int val)
{
    Node *newNode = new Node(val);
    Node *temp = head;

    for (int i = 1; i < idx; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);

    head->next = a;
    a->next = b;

    insert_at_any_position(head, 2, 100);
    print_linked_list(head);

    return 0;
}
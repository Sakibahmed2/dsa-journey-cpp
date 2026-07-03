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

void delete_at_tail(Node *head, Node *&tail, int idx)
{
    Node *temp = head;
    for (int i = 1; i < idx; i++)
    {
        temp = temp->next;
    }

    Node *deletenode = temp->next;
    temp->next = deletenode->next;

    delete deletenode;
    tail = temp;
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

    cout << "Tail Before delete" << tail->value << endl;
    delete_at_tail(head, tail, 4);
    print_linked_list(head);
    cout << "Tail after delete" << tail->value;

    return 0;
}
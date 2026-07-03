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
        cout << temp->value << " ";
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

void check_linked_list_size_same(Node *head1, Node *head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;
    int count1 = 0, count2 = 0;
    while (temp1 != NULL && temp2 != NULL)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    cout << (temp1 == NULL && temp2 == NULL ? "Yes" : "No");
};

int main()
{
    Node *head1 = NULL;
    Node *tail1 = NULL;
    Node *head2 = NULL;
    Node *tail2 = NULL;

    int x;
    while (true)
    {
        cin >> x;
        if (x == -1)
        {
            break;
        }
        insert_at_tail(head1, tail1, x);
    }

    int y;
    while (true)
    {
        cin >> y;
        if (y == -1)
        {
            break;
        }
        insert_at_tail(head2, tail2, y);
    }

    // print_linked_list(head1);
    // print_linked_list(head2);

    check_linked_list_size_same(head1, head2);

    return 0;
}
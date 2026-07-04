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

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    };

    tail->next = newnode;
    tail = newnode;
};

bool check_same_or_not(Node *head1, Node *head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->value != temp2->value)
        {
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return temp1 == NULL && temp2 == NULL;
}

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

    bool ans = check_same_or_not(head1, head2);
    cout << (ans ? "YES" : "NO") << endl;

    return 0;
}
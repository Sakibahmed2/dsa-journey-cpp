#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    long long int value;
    Node *next;

    Node(long long int value)
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

void print_max_min_diff(Node *head)
{
    Node *temp = head;
    int min = INT_MAX;
    int max = INT_MIN;
    while (temp != NULL)
    {
        if (temp->value < min)
        {
            min = temp->value;
        }
        if (temp->value > max)
        {
            max = temp->value;
        }
        temp = temp->next;
    }

    cout << max - min << endl;
};

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    long long int x;
    while (true)
    {
        cin >> x;
        if (x == -1)
        {
            break;
        }
        insert_at_tail(head, tail, x);
    }

    print_max_min_diff(head);

    return 0;
}
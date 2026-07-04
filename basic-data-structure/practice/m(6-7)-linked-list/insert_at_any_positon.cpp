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
    cout << endl;
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

void insert_at_head(Node *&head, int val)
{
    Node *newnode = new Node(val);
    newnode->next = head;
    head = newnode;
}

int get_size(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
};

void insert_at_any_position(Node *&head, int idx, int val)
{
    Node *temp = head;
    Node *newnode = new Node(val);
    for (int i = 1; i < idx; i++)
    {

        if (temp == NULL)
        {
            cout << "Invalid" << endl;
            return;
        };
        temp = temp->next;
    };

    newnode->next = temp->next;
    temp->next = newnode;
};

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int x;
    while (true)
    {
        cin >> x;
        if (x == -1)
        {
            break;
        }
        insert_at_tail(head, tail, x);
    }

    int t;
    cin >> t;
    while (t--)
    {
        int idx, val;
        cin >> idx >> val;
        int size = get_size(head);
        if (idx < 0 || idx > size)
        {
            cout << "Invalid" << endl;
        }
        else if (idx == 0)
        {
            insert_at_head(head, val);
            print_linked_list(head);
        }
        else if (idx == size)
        {
            insert_at_tail(head, tail, val);
            print_linked_list(head);
        }
        else
        {
            insert_at_any_position(head, idx, val);
            print_linked_list(head);
        }
    }

    return 0;
}
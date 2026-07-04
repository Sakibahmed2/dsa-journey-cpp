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
}

int get_size(Node *head)
{
    int cnt = 0;

    Node *temp = head;

    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }

    return cnt;
}

void insert_at_head(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
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
    tail = newNode;
}

void delete_head(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        return;
    }

    Node *deleteNode = head;

    head = head->next;

    delete deleteNode;

    if (head == NULL)
    {
        tail = NULL;
    }
}

void delete_at_any_index(Node *&head, Node *&tail, int index)
{
    if (index == 0)
    {
        delete_head(head, tail);
        return;
    }

    Node *temp = head;

    for (int i = 1; i < index; i++)
    {
        temp = temp->next;
    }

    Node *deleteNode = temp->next;

    temp->next = temp->next->next;

    if (deleteNode == tail)
    {
        tail = temp;
    }

    delete deleteNode;
}

int main()
{
    int q;
    cin >> q;

    Node *head = NULL;
    Node *tail = NULL;

    while (q--)
    {
        int x, v;
        cin >> x >> v;

        if (x == 0)
        {
            insert_at_head(head, tail, v);
        }
        else if (x == 1)
        {
            insert_at_tail(head, tail, v);
        }
        else
        {
            int sz = get_size(head);

            if (v >= 0 && v < sz)
            {
                delete_at_any_index(head, tail, v);
            }
        }

        print_linked_list(head);
    }

    return 0;
}
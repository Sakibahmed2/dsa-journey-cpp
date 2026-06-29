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

Node *reverse(Node *head)
{
    Node *curr = NULL;
    Node *prev = head;

    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev;
};

int main()
{
    int n;
    cin >> n;

    Node *head = NULL;
    Node *tail = NULL;

    // Input in node
    while (n--)
    {
        int x;
        cin >> x;

        Node *newNode = new Node(x);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node *temp = head;

    reverse(temp);

    while (temp != NULL)
    {
        cout << temp->value << endl;
        temp = temp->next;
    }

    return 0;
}
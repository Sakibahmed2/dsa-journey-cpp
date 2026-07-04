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

int search_idx(Node *head, long long int target)
{
    Node *temp = head;
    int index = 0;

    while (temp != NULL)
    {
        if (temp->value == target)
        {
            return index;
        }

        temp = temp->next;
        index++;
    }

    return -1;
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        Node *head = NULL;
        Node *tail = NULL;

        while (true)
        {
            long long int x;
            cin >> x;
            if (x == -1)
            {
                break;
            }
            insert_at_tail(head, tail, x);
        }
        long long target;
        cin >> target;

        int ans = search_idx(head, target);
        cout << ans << endl;
    }

    return 0;
}
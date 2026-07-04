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

void remove_duplicate(Node *&head)
{
    for (Node *i = head; i != NULL; i = i->next)
    {
        Node *prev = i;
        Node *j = i->next;

        while (j != NULL)
        {
            if (i->value == j->value)
            {
                prev->next = j->next;
                delete j;
                j = prev->next;
            }
            else
            {
                prev = j;
                j = j->next;
            }
        }
    }
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

    remove_duplicate(head);
    print_linked_list(head);

    return 0;
}

// Theoretical question explanation:

// Question analysis
// আমাকে একটি Singly Linked List দেওয়া হবে। যদি Linked List-এ কোনো Duplicate Value থাকে, তাহলে Duplicate Node গুলো Remove করে শুধুমাত্র Unique Value Print করতে হবে।

// Observation:
// যদি i এবং j এর Value একই হয়, তাহলে j Node টাকে Delete করতে হবে।
// আর যদি একই না হয়, তাহলে prev কে এক ধাপ সামনে এবং j কেও এক ধাপ সামনে নিয়ে যেতে হবে।

// Test case analysis:
// Linked list: 10 -> 20 -> 30
// i = first 10
// prev = first 10
// j = 20

// 10 != 20
// prev = 20
// j = 30

// 10 != 30
// তাই prev = 30
// j = second 20

// 10 != 20
// তাই prev = second 20
// আর কোনো Duplicate না থাকায় শেষ হবে।
// Final Output:
// 10 -> 20 -> 30
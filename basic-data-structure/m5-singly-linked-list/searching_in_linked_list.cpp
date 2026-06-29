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

    int target;
    cin >> target;

    Node *temp = head;
    bool flag = false;
    while (temp != NULL)
    {
        if (temp->value == target)
        {
            flag = true;
            break;
        }
        else
        {
            flag == false;
        }

        temp = temp->next;
    }

    cout << (flag ? "Founded" : "Not founded");

    return 0;
}
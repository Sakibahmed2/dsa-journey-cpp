#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
};

int main()
{
    Node a, b, c;

    a.value = 10;
    b.value = 20;
    c.value = 30;

    // cout << a.value << " " << b.value << " " << c.value;

    cout << a.value << endl;
    cout << (*a.next).value << endl;

    return 0;
}
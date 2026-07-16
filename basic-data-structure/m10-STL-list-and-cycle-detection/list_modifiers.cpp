#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l = {10, 20, 30, 40};
    // list<int> l2;

    // // l2 = l;
    // l2.assign(l.begin(), l.end());

    l.push_back(50); // insert at tail
    l.push_front(5); // insert at head

    l.pop_back();  // delete at tail
    l.pop_front(); // delete at head

    // cout << *next(l.begin(), 2);  // access ith elemnet

    l.insert(next(l.begin(), 2), 25); // insert at any position
    l.erase(next(l.begin(), 2));      // delete at any position

    // replace(l.begin(), l.end(), 10, 20); // Replace all the value with replace_value.

    auto it = find(l.begin(), l.end(), 10);
    if (it == l.end())
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << "Founded" << endl;
    }

    for (int x : l)
    {
        cout << x << endl;
    }

    return 0;
}
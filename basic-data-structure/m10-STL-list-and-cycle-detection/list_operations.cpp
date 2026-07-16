#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l = {4, 2, 5, 3, 1, 2, 3, 5};

    // l.remove(1); // remove from list

    // l.sort(); // sort asc
    // l.sort(greater<int>()); // sort dsc

    // l.unique(); // remove duplicate: must sort the list first

    l.reverse();

    for (int x : l)
    {
        cout << x << " ";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l;

    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        l.push_back(val);
    }

    l.reverse();

    for(int x : l)
    {
        cout << x << " ";
    }

    return 0;
}
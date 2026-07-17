#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l1;
    list<int> l2;

    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        l1.push_back(val);
    }

    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        l2.push_back(val);
    }

    if (l1.size() == l2.size())
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
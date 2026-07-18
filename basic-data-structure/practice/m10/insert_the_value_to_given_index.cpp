#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    list<int> l;

    while (t--)
    {
        int idx, val;
        cin >> idx >> val;

        if (idx > l.size())
        {
            cout << "Invalid" << endl;
            continue;
        }

        l.insert(next(l.begin(), idx), val);

        for (int x : l)
        {
            cout << x << " ";
        }
        cout << endl;
        l.reverse();
        for (int x : l)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
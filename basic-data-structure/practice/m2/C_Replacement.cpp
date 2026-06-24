#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<int> v(t);

    // Take input
    for (int &x : v)
    {
        cin >> x;
    }

    // Update value
    for (int &x : v)
    {
        if (x < 0)
        {
            x = 2;
        }
        else if (x > 0)
        {
            x = 1;
        }
    }

    // Printing result
    for (int x : v)
    {
        cout << x << " ";
    }

    return 0;
}
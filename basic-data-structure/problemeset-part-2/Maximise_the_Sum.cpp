#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> v(5);
        for (int &x : v)
        {
            cin >> x;
        }

        int mx = 0;
        for (int i = 1; i < 5; i++)
        {
            if (v[mx] > v[i])
            {
                v[i] = v[i] * -1;
            }
            else
            {
                v[mx] = v[mx] * -1;
                mx = v[i];
            }
        }

        for (int x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
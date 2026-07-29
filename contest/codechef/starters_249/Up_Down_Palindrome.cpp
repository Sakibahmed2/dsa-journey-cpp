#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> v(n);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        bool ok = true;

        long long L = 0;
        long long R = 1e18;

        for (int i = 0; i < n / 2; i++)
        {
            long long a = v[i];
            long long b = v[n - 1 - i];

            long long diff = abs(a - b);

            if (diff == 0)
            {
                continue;
            }
            else if (diff == 2)
            {
                L = max(L, min(a, b));
                R = min(R, max(a, b) - 1);
            }
            else
            {
                ok = false;
                break;
            }
        }

        if (ok && L <= R)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
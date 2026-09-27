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

        long long sum = 0;
        int mn = 0;
        bool possible = true;
        bool deleted = false;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            sum += x;
            mn = min(mn, x);

            if (sum < 0)
            {
                if (deleted)
                {
                    possible = false;
                }
                else
                {
                    sum -= mn;
                    deleted = true;
                }
            }
        }
        cout << (possible ? "YES" : "NO") << endl;
    }

    return 0;
}
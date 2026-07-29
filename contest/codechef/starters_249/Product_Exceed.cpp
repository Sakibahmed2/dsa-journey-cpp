#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int X, Y, P;
        cin >> X >> Y >> P;

        int ans = INT_MAX;

        for (int i = 0; i <= 100; i++)
        {
            int newX = X + i;

            int j = 0;
            while (newX * (Y + j) < P)
            {
                j++;
            }

            ans = min(ans, i + j);
        }

        cout << ans << endl;
    }

    return 0;
}
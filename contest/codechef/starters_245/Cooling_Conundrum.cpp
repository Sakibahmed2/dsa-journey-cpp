#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;

        int ans = 0;
        while (x > y)
        {
            ans += (x + 9) / 10;

            x--;
        }

        cout << ans << endl;
    }

    return 0;
}
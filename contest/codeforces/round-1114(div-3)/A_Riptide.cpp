#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int round = 0;
        int a, b, c;
        cin >> a >> b >> c;

        while (true)
        {
            if (a == b || b == c || c == a)
            {
                break;
            }

            int mx = max({a, b, c});
            int mn = min({a, b, c});

            if (a == mx)
                a--;
            else if (b == mx)
                b--;
            else
                c--;

            if (a == mn)
                a++;
            else if (b == mn)
                b++;
            else
                c++;

            round++;
        }

        cout << round << endl;
    }

    return 0;
}
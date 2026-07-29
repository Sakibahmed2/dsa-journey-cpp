#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, z;
        cin >> x >> y >> z;

        if (y >= z)
        {
            cout << "-1" << endl;
            continue;
        }

        int chefMoney = 0;
        int cnt = 0;
        while (chefMoney < x)
        {
            chefMoney += z;
            x += y;
            cnt++;
        }

        cout << cnt << endl;
    }

    return 0;
}
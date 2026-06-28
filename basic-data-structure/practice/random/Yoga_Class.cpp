#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;

        int max_earn;
        if (x * 2 < y)
        {
            max_earn = y * (n / 2) + (n % 2) * x;
            
        }
        else
        {
            max_earn = n * x;
        }

        cout << max_earn << endl;
    }

    return 0;
}
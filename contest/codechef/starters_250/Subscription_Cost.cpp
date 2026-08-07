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

        int totalCost = 0;
        if (n <= 3)
        {
            totalCost = n * x;
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                if (i <= 3)
                {
                    totalCost += x;
                }
                else
                {
                    totalCost += y;
                }
            }
        }

        cout << totalCost << endl;
    }

    return 0;
}
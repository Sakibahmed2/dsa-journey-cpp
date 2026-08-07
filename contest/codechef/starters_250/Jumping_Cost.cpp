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

        vector<int> a(n + 1);

        for (int i = 1; i <= n; i++)
            cin >> a[i];

        vector<int> v2(n + 1, 0);

        int ans = 0;

        for (int i = 2; i <= n; i++)
        {
            v2[i] = INT_MIN;

            for (int j = 1; j < i; j++)
            {
                v2[i] = max(v2[i], v2[j] + a[i] - i + j);
            }

            ans = max(ans, v2[i]);
        }

        cout << ans << endl;
    }
}
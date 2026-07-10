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
        int arr[n];
        for (int &x : arr)
        {
            cin >> x;
        }

        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            ans = max(ans, min(arr[i], arr[i + 1]));
        }

        cout << ans << endl;
    }

    return 0;
}
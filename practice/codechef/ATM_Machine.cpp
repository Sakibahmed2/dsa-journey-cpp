#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int &x : arr)
        {
            cin >> x;
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= k)
            {
                cout << 1;
                k -= arr[i];
            }
            else
            {
                cout << 0;
            }
        }
        cout << endl;
    }

    return 0;
}
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
        vector<long long> arr(n);
        for (long long &x : arr)
        {
            cin >> x;
        }

        long long totalWait = 0;
        long long entryTime = arr[0];

        for (int i = 1; i < n; i++)
        {
            if (arr[i] >= entryTime)
            {
                entryTime = arr[i];
            }
            else
            {
                totalWait += (entryTime - arr[i]);
            }
        }

        
        cout << totalWait << endl;
    }

    return 0;
}
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
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int totalSum = 0;
        for (int x : arr)
        {
            totalSum += x;
        }

        int flag = false;
        for (int i = 0; i < n; i++)
        {
            int res = arr[i] - totalSum;
            if (res % 2 == 0)
            {
                flag = true;
                break;
            }
        }

        cout << (flag ? "Yes\n" : "No\n");
    }

    return 0;
}
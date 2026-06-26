#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    bool flag = false;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            flag = true;
            break;
        }
    }

    cout << (flag ? "YES" : "NO");

    return 0;
}
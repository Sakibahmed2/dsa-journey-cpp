#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    while (t--)
    {
        int x;
        cin >> x;
        bool flag = false;
        int start = 0, end = arr.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] == x)
            {
                flag = true;
                break;
            }
            else if (arr[mid] < x)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        cout << (flag ? "found" : "not found") << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> arr(n);
    for (int &x : arr)
    {
        cin >> x;
    }

    sort(arr.begin(), arr.end());

    while (t--)
    {
        int x;
        cin >> x;

        bool flag = false;
        int left = 0, right = arr.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] == x)
            {
                flag = true;
                break;
            }
            else if (arr[mid] < x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
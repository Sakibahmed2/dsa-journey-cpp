#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, target;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr)
    {
        cin >> x;
    }
    cin >> target;
    sort(arr.begin(), arr.end());

    int left = 0, right = n - 1;
    bool flag = false;
    while (left <= right)
    {
        int mid = right + (right - left) / 2;
        if (arr[mid] == target)
        {
            flag = true;
            break;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << (flag ? "Founded" : "Not founded");

    return 0;
}
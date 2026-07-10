#include <bits/stdc++.h>
using namespace std;

vector<int> next_higher_peak(vector<int> &heights)
{
    int n = heights.size();
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        ans[i] = -1;

        for (int j = i + 1; j < n; j++)
        {
            if (heights[j] > heights[i])
            {
                ans[i] = heights[j];
                break;
            }
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr)
    {
        cin >> x;
    }

    vector<int> ans = next_higher_peak(arr);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}
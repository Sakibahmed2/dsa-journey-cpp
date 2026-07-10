#include <bits/stdc++.h>
using namespace std;

int min_sub_array_len(int target, vector<int> &nums)
{
    int left = 0;
    int sum = 0;
    int ans = INT_MAX;

    for (int right = 0; right < nums.size(); right++)
    {
        sum += nums[right];

        while (sum >= target)
        {
            ans = min(ans, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }

    return (ans == INT_MAX) ? 0 : ans;
};

int main()
{
    int target;
    cin >> target;
    vector<int> arr;
    int value;

    while (cin >> value)
    {
        arr.push_back(value);
    }

    int ans = min_sub_array_len(target, arr);

    cout << ans;

    return 0;
}
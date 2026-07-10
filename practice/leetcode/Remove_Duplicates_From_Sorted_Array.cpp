#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int i = 0;
    for (int j = 1; j < nums.size(); j++)
    {
        if (nums[i] != nums[j])
        {
            i++;
            nums[i] = nums[j];
        }
    }

    return i + 1;
}

int main()
{
    vector<int> arr;
    int x;
    while (cin >> x)
    {
        arr.push_back(x);
    }

    int ans = removeDuplicates(arr);
    cout << ans;

        return 0;
}
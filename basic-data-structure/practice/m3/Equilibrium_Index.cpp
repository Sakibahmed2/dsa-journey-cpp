#include <bits/stdc++.h>
using namespace std;

int equilibrium_idx(vector<int> arr)
{
    int totalSum = 0;
    for (int x : arr)
    {
        totalSum += x;
    }

    int leftSum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int rightSum = totalSum - leftSum - arr[i];
        if (leftSum == rightSum)
        {
            return i;
        }

        leftSum += arr[i];
    }

    return 0;
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr)
    {
        cin >> x;
    }

    int result = equilibrium_idx(arr);

    cout << result;

    return 0;
}
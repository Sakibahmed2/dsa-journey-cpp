#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n]; // Space Complexity O(n)
    // int arr[n][n]; // Space Complexity O(n*n)
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    return 0;
}

// Space complexity is: O(N)
// Because it take N th variable
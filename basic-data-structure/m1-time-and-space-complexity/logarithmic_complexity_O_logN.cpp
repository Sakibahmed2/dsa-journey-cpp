#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;                          // O(1)
    cin >> n;                       // O(1)
    for (int i = 1; i <= n; i *= 2) // O(logN)
    {
        cout << i << endl;
    }
    return 0;
}

// if a loop variable is multiplied or divided by a constant factor in each iteration, the time complexity is logarithmic: O(log n).

// Note: It is not always logarithmic just because you see * or /.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;    // O(1)
    cin >> n; // O(1)

    for (int i = 0; i < n; i++) // O(n)
    {
        cout << i << " ";
    }

    cout << endl; // O(1)

    for (int i = 0; i < n; i += 2) // O(n)
    {
        cout << i << " ";
    }

    return 0; // O(1)
}

//  O(n + n + 4)
//    => O(n + n) (Remove 4 because we dont cal constant)
//    => O(2n) (n + n = 2n)
//    => O(n) (Remove 2 because we dont cal constant)

// Overall time complexity is: O(n)
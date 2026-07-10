#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, y;
        cin >> r >> y;
        int remainingYellow = max(0, y - r);

        cout << r + remainingYellow / 2 << endl;
    }

    return 0;
}
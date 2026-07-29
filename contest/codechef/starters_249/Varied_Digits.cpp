#include <bits/stdc++.h>
using namespace std;

int main()
{
    int digits;
    cin >> digits;

    if (digits / 10 == digits % 10)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }

    return 0;
}

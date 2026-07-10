#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int point = 0;

    if (a > 0)
    {
        point += a * 3;
    }
    if (b > 0)
    {
        point += b;
    }

    cout << point << endl;

    return 0;
}
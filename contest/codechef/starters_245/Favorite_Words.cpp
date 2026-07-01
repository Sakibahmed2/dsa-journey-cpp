#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    bool flag = false;
    if(s.front() == 'c' || s.back() == 'f')
    {
        flag = true;
    }

    cout << (flag ? "Yes" : "No");

    return 0;
}
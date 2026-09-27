#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;

    if (str[0] == str[2] && str[1] == str[3])
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int d, t;
    cin >> d >> t;
    if(t >= d) 
    {
        cout << 0;
        return 0;
    }

    cout << d - t;


    return 0;
}   
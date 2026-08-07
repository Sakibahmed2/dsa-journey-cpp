#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s;
    cin >> s;

    int slides = s * 30;

    if (slides >= 600)
    {
        cout << 0 << endl;
        return 0;
    }

    int cnt = 0;

    while (slides < 600)
    {
        cnt++;
        slides += 30;
    }

    cout << cnt << endl;

    return 0;
}
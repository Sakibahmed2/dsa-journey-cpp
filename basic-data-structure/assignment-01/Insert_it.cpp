#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v1(n);
    for (int &x : v1)
    {
        cin >> x;
    }

    int m;
    cin >> m;
    vector<int> v2(m);
    for (int &x : v2)
    {
        cin >> x;
    }

    int idx;
    cin >> idx;

    v1.insert(v1.begin() + idx, v2.begin(), v2.end());

    for (int x : v1)
    {
        cout << x << " ";
    }

    return 0;
}
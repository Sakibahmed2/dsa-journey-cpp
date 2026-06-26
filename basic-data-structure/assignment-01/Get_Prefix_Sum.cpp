#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        v[i] = x + v[i - 1];
    }

    for (int i = v.size() - 1; i > 0; i--)
    {
        cout << v[i] << " ";
    }

    return 0;
}
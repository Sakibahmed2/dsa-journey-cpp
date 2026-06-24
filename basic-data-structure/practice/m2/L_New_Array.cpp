#include <bits/stdc++.h>
using namespace std;

vector<int> comb_arr(vector<int> a, vector<int> b)
{
    vector<int> v;

    v.reserve(a.size() + v.size());

    v.insert(v.end(), b.begin(), b.end());
    v.insert(v.end(), a.begin(), a.end());

    return v;
};

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<int> v = comb_arr(a, b);

    for (int x : v)
    {
        cout << x << " ";
    }

    return 0;
}
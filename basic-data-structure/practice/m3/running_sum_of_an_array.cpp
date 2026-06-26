#include <bits/stdc++.h>
using namespace std;

vector<int> running_sum(vector<int> &v)
{
    int n = v.size();

    vector<int> prefix(n);
    prefix[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = v[i] + prefix[i - 1];
    }

    return prefix;
};

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &x : v)
    {
        cin >> x;
    }

    vector<int> res = running_sum(v);

    for (int x : res)
    {
        cout << x << " ";
    }

    return 0;
}
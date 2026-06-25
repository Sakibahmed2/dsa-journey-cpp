#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<long long int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    vector<long long int> prefix(n + 1);
    prefix[1] = v[1];
    for (int i = 2; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + v[i];
    }

    while (q--)
    {
        int left, right;
        cin >> left >> right;
        long long int sum = 0;

        if (left == 1)
        {
            sum = prefix[right];
        }
        else
        {
            sum = prefix[right] - prefix[left - 1];
        }

        cout << sum << endl;
    }

    return 0;
}
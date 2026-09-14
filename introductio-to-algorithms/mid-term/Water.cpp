#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<long long int> v(n);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        int first = 0;
        int second = 1;

        if (v[first] < v[second])
        {
            swap(first, second);
        }

        for (int i = 2; i < n; i++)
        {
            if (v[i] > v[first])
            {
                second = first;
                first = i;
            }
            else if (v[i] > v[second])
            {
                second = i;
            }
        }

        if (first < second)
        {
            cout << first << " " << second << endl;
        }
        else
        {
            cout << second << " " << first << endl;
        }
    }

    return 0;
}
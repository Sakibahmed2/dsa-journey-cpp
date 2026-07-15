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
        vector<int> v(n);
        for (int &x : v)
        {
            cin >> x;
        }

        int evenStart = 0;
        int oddStart = 0;

        for (int i = 0; i < n; i++)
        {

            if (i % 2 == 0)
            {
                if (v[i] % 2 != 0)
                {
                    evenStart++;
                }
            }
            else
            {
                if (v[i] % 2 == 0)
                {
                    evenStart++;
                }
            }

            if (i % 2 == 0)
            {
                if (v[i] % 2 == 0)
                {
                    oddStart++;
                }
            }
            else
            {
                if (v[i] % 2 != 0)
                {
                    oddStart++;
                }
            }
        }

        cout << min(evenStart, oddStart) << endl;
    }

    return 0;
}
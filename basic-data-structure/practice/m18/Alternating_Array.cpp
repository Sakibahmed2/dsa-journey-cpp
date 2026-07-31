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

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int oddEven = 0;
        int evenOdd = 0;

        for (int i = 0; i < n; i++)
        {

            if (i % 2 == 0)
            {
                if (v[i] % 2 == 0)
                    oddEven++;
            }
            else
            {
                if (v[i] % 2 != 0)
                    oddEven++;
            }

            if (i % 2 == 0)
            {
                if (v[i] % 2 != 0)
                    evenOdd++;
            }
            else
            {
                if (v[i] % 2 == 0)
                    evenOdd++;
            }
        }

        cout << min(oddEven, evenOdd) << endl;
    }

    return 0;
}
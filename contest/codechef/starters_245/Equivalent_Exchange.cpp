#include <bits/stdc++.h>
using namespace std;

bool check(int x, int k, vector<int> a)
{
    int red_stone = x;
    int blue_stone = k - x;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > 0)
        {
            red_stone += a[i];
            blue_stone -= a[i];
        }
        else
        {
            blue_stone += (-a[i]);
            red_stone -= (-a[i]);
        }

        if (red_stone < 0 || blue_stone < 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x;
        cin >> n >> k;
        vector<int> arr(n);
        for (int &x : arr)
        {
            cin >> x;
        }

        bool flag = false;
        for (int i = 0; i <= k; i++)
        {
            if (check(i, k, arr))
            {
                flag = true;
                break;
            }
        }
        cout << (flag ? "Yes" : "No") << endl;
    }

    return 0;
}
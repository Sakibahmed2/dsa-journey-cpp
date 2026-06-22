#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    while (q--)
    {
        int num;
        cin >> num;
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == num)
            {
                flag = true;
            }
        }
        cout << (flag ? "found" : "not found") << endl;
    }

    return 0;
}
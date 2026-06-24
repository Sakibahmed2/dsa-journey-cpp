#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &x : v)
    {
        cin >> x;
    }

    int start = 0, end = v.size() - 1;
    while (start <= end)
    {

        int temp = v[start];
        v[start] = v[end];
        v[end] = temp;

        start++;
        end--;
    }

    for (int x : v)
    {
        cout << x << " ";
    }

    return 0;
}
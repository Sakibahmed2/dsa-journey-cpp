#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    stack<int> st;
    queue<int> qu;

    if (n != m)
    {
        cout << "NO" << endl;
        return 0;
    }

    int val;
    while (n--)
    {
        cin >> val;
        st.push(val);
    }

    while (m--)
    {
        cin >> val;
        qu.push(val);
    }

        while (!st.empty() && !qu.empty())
    {
        if (st.top() != qu.front())
        {
            cout << "NO" << endl;
            return 0;
        }
        st.pop();
        qu.pop();
    }

    cout << "YES" << endl;

    return 0;
}
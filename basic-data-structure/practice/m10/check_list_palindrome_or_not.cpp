#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l;

    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        l.push_back(val);
    }

    bool flag = true;
    while(l.size() > 1)
    {
        if (l.front() != l.back())
        {
            flag = false;
            break;
        }
        l.pop_back();
        l.pop_front();
    }

    if (flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
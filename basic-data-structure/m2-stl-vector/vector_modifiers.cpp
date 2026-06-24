#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    // vector<int> v2;
    // v2 = v;

    // v.insert(v.begin() + 2, 100);
    // v.erase(v.begin() + 2, v.begin() + 3);

    // replace(v.begin(), v.end(), 5, 100);
    // auto it = find(v.begin(), v.end(), 100);
    // if (it == v.end())
    // {
    //     cout << "Not founded" << endl;
    // }
    // else
    // {
    //     cout << "Founded" << endl;
    // }

    // for (int x : v)
    // {
    //     cout << x << " ";
    // }

    // Print vector using iterator
    for (auto it = v.begin(); it < v.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}
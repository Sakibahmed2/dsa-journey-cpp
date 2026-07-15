#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l = {1, 2, 3, 14, 5};

    int arr[] = {10, 20, 30, 40};

    vector<int> v = {50, 60, 70, 80};

    // list<int> l2(l);
    // list<int> l2(arr, arr + 4);
    list<int> l2(v.begin(), v.end());

    // l2.clear();

    // if (l2.empty())
    // {
    //     cout << "Empty" << endl;
    // }
    // else
    // {
    //     cout << "Not empty" << endl;
    // }

    // l2.resize(2);

    for (int x : l2)
    {
        cout << x << " ";
    }

    // cout << l.size() << endl;

    return 0;
}
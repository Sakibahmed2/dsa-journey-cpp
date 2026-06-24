#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    cout << v.size() << endl;
    v.clear();
    cout << v.size() << endl;
    cout << v[2] << endl;
    return 0;
}
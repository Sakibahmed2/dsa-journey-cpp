#include <bits/stdc++.h>
using namespace std;

int main()
{
    // vector<int> v; // Type 1
    // vector<int> v(10); // Type 2
    // vector<int> v(10, -1); // type 3
    // vector<int> v2(v); // Type 4
    // vector<int> v = {1, 2, 3, 4, 5} // Type 5
    int arr[5] = {1, 2, 3, 4, 5};
    vector<int> v(arr, arr + 5); // Type 5

    cout << v.size() << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}
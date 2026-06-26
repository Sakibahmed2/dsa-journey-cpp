#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        string s1, s2;
        cin >> s1 >> s2;

        string result;
        result.reserve(a);

        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == s2[i])
            {
                result.push_back(s1[i]);
            }
        }

        cout << result << endl;
    }

    return 0;
}
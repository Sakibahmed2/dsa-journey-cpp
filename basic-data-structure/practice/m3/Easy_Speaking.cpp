#include <bits/stdc++.h>
using namespace std;

bool is_vowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int consonants_count = 0;
        bool flag = false;

        for (int i = 0; i < n; i++)
        {
            char c;
            cin >> c;
            if (is_vowel(c))
            {
                consonants_count = 0;
            }
            else
            {
                consonants_count++;
                if (consonants_count >= 4)
                {
                    flag = true;
                }
            }
        }

        cout << (flag ? "Yes" : "No") << endl;
    }

    return 0;
}
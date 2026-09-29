#include <bits/stdc++.h>
using namespace std;

long long int factorial(long long int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    long long int n;
    cin >> n;
    long long int ans = factorial(n);
    cout << ans << endl;
    return 0;
}
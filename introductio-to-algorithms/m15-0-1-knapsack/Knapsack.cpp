#include <bits/stdc++.h>
using namespace std;

int val[1005], weight[1005];

int knapsack(int i, int bag_limit)
{
    if (i < 0 || bag_limit <= 0)
        return 0;

    if (weight[i] <= bag_limit)
    {
        //  2. Option
        // 1. bag a rakhbo,
        int op1 = knapsack(i - 1, bag_limit - weight[i]) + val[i];

        // 2. Bag a rakhbo na
        int op2 = knapsack(i - 1, bag_limit);

        return max(op1, op2);
    }
    else
    {
        // 1. Option
        // Bag a rakhte parbo na
        return knapsack(i - 1, bag_limit);
    }
}

int main()
{
    int n, bag_limit;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> val[i];

    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cin >> bag_limit;

    cout << knapsack(n - 1, bag_limit) << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int val[1005], weight[1005];
int dp[1005][1005];

int knapsack(int i, int bag_limit)
{
    if (i < 0 || bag_limit <= 0)
        return 0;

    if (dp[i][bag_limit] != -1)
        return dp[i][bag_limit];

    if (weight[i] <= bag_limit)
    {
        int op1 = knapsack(i - 1, bag_limit - weight[i]) + val[i];
        int op2 = knapsack(i - 1, bag_limit);

        dp[i][bag_limit] = max(op1, op2);
        return dp[i][bag_limit];
    }
    else
    {
        dp[i][bag_limit] = knapsack(i - 1, bag_limit);
        return dp[i][bag_limit];
    }
}

int main()
{
    int n, bag_limit;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= bag_limit; j++)
            dp[i][j] = -1;

    for (int i = 0; i < n; i++)
        cin >> val[i];

    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cin >> bag_limit;

    cout << knapsack(n - 1, bag_limit) << endl;

    return 0;
}
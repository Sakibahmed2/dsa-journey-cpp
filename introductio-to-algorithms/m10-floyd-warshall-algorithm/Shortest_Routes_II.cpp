#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    const long long INF = 1e18;

    long long adj_mat[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                adj_mat[i][j] = 0;
            else
                adj_mat[i][j] = INF;
        }
    }

    while (m--)
    {
        int a, b;
        long long c;

        cin >> a >> b >> c;

        a--;
        b--;

        adj_mat[a][b] = min(adj_mat[a][b], c);
        adj_mat[b][a] = min(adj_mat[b][a], c);
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj_mat[i][k] != INF &&
                    adj_mat[k][j] != INF &&
                    adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
                {
                    adj_mat[i][j] =
                        adj_mat[i][k] + adj_mat[k][j];
                }
            }
        }
    }

    while (q--)
    {
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        if (adj_mat[a][b] == INF)
            cout << -1 << '\n';
        else
            cout << adj_mat[a][b] << '\n';
    }

    return 0;
}
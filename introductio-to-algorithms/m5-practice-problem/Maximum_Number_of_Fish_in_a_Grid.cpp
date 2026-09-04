#include <bits/stdc++.h>
using namespace std;

int grid[15][15];
bool vis[15][15];
int n, m;
int sum;

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool is_valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;

    sum += grid[si][sj];

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if (is_valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != 0)
        {
            dfs(ci, cj);
        }
    }
};

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int mx = 0;
    memset(vis, false, sizeof(vis));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] != 0)
            {
                sum = 0;
                dfs(i, j);
                mx = max(sum, mx);
            }
        }
    }

    cout << mx << endl;

    return 0;
}
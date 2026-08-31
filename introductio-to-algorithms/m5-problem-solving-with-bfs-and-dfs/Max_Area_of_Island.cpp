#include <bits/stdc++.h>
using namespace std;

int grid[55][55];
bool vis[55][55];

int n, m, cnt, mx;

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

    cnt++;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if (is_valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 1)
        {
            dfs(ci, cj);
        }
    }
}

int main()
{
    cin >> n >> m;
    mx = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == 1)
            {
                cnt = 0;
                dfs(i, j);
                mx = max(cnt, mx);
            }
        }
    }

    cout << mx << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int grid[105][105];
bool vis[105][105];
int n, m;

vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool is_valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

int cnt = 0;

void dfs(int si, int sj)
{
    // cout << grid[si][sj];
    vis[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if (is_valid(ci, cj) == false)
        {
            cnt++;
        }
        else if (is_valid(ci, cj) == true && grid[ci][cj] == 0)
        {
            cnt++;
        }
        else if (is_valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 1)
        {
            dfs(ci, cj);
        }
    }
}

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

    memset(vis, false, sizeof(vis));

    dfs(1, 1);

    cout << cnt << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, m;
bool vis[105][105];
int grid[105][105];

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool flag;

bool is_valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if (!is_valid(ci, cj))
        {
            flag = false;
        }

        if (is_valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 0)
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

    memset(vis, false, sizeof(vis));

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == 0)
            {
                flag = true;
                dfs(i, j);
                if (flag)
                {
                    cnt++;
                }
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
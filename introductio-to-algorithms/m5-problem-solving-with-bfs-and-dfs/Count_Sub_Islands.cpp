#include <bits/stdc++.h>
using namespace std;

int n, m;

bool vis[505][505];
bool flag;

vector<pair<int, int>> d = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};

bool is_valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;

    return true;
}

void dfs(int si, int sj, vector<vector<int>> &grid1,
         vector<vector<int>> &grid2)
{
    vis[si][sj] = true;

    if (grid1[si][sj] == 0)
    {
        flag = false;
    }

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if (is_valid(ci, cj) && !vis[ci][cj] && grid2[ci][cj] == 1)
        {
            dfs(ci, cj, grid1, grid2);
        }
    }
}

int main()
{
    int cnt = 0;
    cin >> n >> m;

    vector<vector<int>> grid1(n, vector<int>(m));
    vector<vector<int>> grid2(n, vector<int>(m));

    // Input grid1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid1[i][j];
        }
    }

    // Input grid2
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid2[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid2[i][j] == 1)
            {
                flag = true;
                dfs(i, j, grid1, grid2);
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
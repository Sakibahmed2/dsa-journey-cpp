#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];

pair<int, int> parent[1005][1005];

int n, m;

vector<pair<int, int>> d = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}};

bool is_valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;

    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;

    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        int pi = par.first;
        int pj = par.second;

        for (int i = 0; i < 4; i++)
        {
            int ci = pi + d[i].first;
            int cj = pj + d[i].second;

            if (is_valid(ci, cj) &&
                !vis[ci][cj] &&
                (grid[ci][cj] == '.' || grid[ci][cj] == 'D'))
            {
                vis[ci][cj] = true;

                parent[ci][cj] = {pi, pj};

                q.push({ci, cj});
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    int si, sj;
    int di, dj;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];

            if (grid[i][j] == 'R')
            {
                si = i;
                sj = j;
            }

            if (grid[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));

    bfs(si, sj);

    if (!vis[di][dj])
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << grid[i][j];

            cout << endl;
        }

        return 0;
    }

    int ci = di;
    int cj = dj;

    while (grid[ci][cj] != 'R')
    {
        grid[ci][cj] = 'X';

        int pi = parent[ci][cj].first;
        int pj = parent[ci][cj].second;

        ci = pi;
        cj = pj;
    }

    grid[di][dj] = 'D';

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << grid[i][j];

        cout << endl;
    }

    return 0;
}
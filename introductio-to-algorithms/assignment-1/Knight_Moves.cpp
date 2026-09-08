#include <bits/stdc++.h>
using namespace std;

int n, m;

bool vis[105][105];
int level[105][105];

vector<pair<int, int>> d = {
    {-2, -1},
    {-2, 1},
    {2, -1},
    {2, 1},
    {-1, -2},
    {-1, 2},
    {1, -2},
    {1, 2}};

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
    level[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        int pi = par.first;
        int pj = par.second;

        for (int i = 0; i < 8; i++)
        {
            int ci = pi + d[i].first;
            int cj = pj + d[i].second;

            if (is_valid(ci, cj) && !vis[ci][cj])
            {
                vis[ci][cj] = true;
                level[ci][cj] = level[pi][pj] + 1;

                q.push({ci, cj});
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;

        int ki, kj, qi, qj;

        cin >> ki >> kj >> qi >> qj;

        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(vis));

        bfs(ki, kj);

        if (vis[qi][qj])
            cout << level[qi][qj] << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}
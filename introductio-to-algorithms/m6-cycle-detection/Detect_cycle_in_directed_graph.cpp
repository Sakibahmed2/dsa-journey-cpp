#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[105];
bool vis[105];
bool cycle;
bool path_vis[105];

void dfs(int src)
{
    vis[src] = true;
    path_vis[src] = true;

    for (int child : adj_list[src])
    {
        if (vis[child] && path_vis[child])
            cycle = true;

        if (!vis[child])
        {
            dfs(child);
        }
    }
    path_vis[src] = false;
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
    }

    memset(vis, false, sizeof(vis));
    memset(path_vis, false, sizeof(path_vis));

    cycle = false;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    if (cycle)
        cout << "Cycle detected" << endl;
    else
        cout << "No cycle" << endl;

    return 0;
}
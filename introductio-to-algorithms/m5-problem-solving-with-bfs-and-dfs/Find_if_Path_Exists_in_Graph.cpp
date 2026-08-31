#include <bits/stdc++.h>
using namespace std;

bool vis[200005];
vector<int> adj[200005];

void dfs(int src)
{
    vis[src] = true;

    for (int child : adj[src])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int src, dst;
    cin >> src >> dst;

    memset(vis, false, sizeof(vis));
    dfs(src);
    cout << vis[dst] << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1001];
bool vis[1001];
int level[1001];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : adj_list[par])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
            }
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
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int src, dst;
        cin >> src >> dst;

        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));

        bfs(src);
        cout << level[dst] << endl;
    }

    return 0;
}
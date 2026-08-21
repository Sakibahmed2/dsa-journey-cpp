#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool visited[1005];

void bfs(int src)
{
    queue<int> qu;
    qu.push(src);
    visited[src] = 0;

    while (!qu.empty())
    {
        // Take node
        int parent = qu.front();
        qu.pop();

        // Children push
        for (int child : adj_list[parent])
        {
            if (!visited[parent])
            {
                qu.push(child);
                visited[child] = true;
            }
        }
    }
};

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

    memset(visited, false, sizeof(visited));

    int src, dest;
    cin >> src >> dest;

    bfs(src);

    if (visited[dest])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
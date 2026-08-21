#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool visited[1005];

void bfs(int src)
{
    queue<int> qu;
    qu.push(src);
    visited[src] = true;

    while (!qu.empty())
    {
        // 1. Ber kore anaa
        int parent = qu.front();
        qu.pop();

        // 2. oi node niye kaj koraa
        cout << parent << " ";

        // 3. Children push kora
        for (int child : adj_list[parent])
        {
            if (visited[child] == false)
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
    bfs(0);

    return 0;
}
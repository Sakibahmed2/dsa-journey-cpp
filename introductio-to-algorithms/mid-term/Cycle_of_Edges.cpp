#include <bits/stdc++.h>
using namespace std;

int par[100005];
int group_size[100005];

int find(int node)
{
    if (par[node] == node)
        return node;
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2)
{
    int leaderA = find(node1);
    int leaderB = find(node2);
    if (group_size[leaderA] >= group_size[leaderB])
    {
        par[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}

int main()
{
    memset(par, -1, sizeof(par));
    memset(group_size, 1, sizeof(group_size));

    int n, e;
    cin >> n >> e;

    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        group_size[i] = i;
    }

    int cnt = 0;
    while (e--)
    {
        int a, b;
        cin >> a >> b;

        if (find(a) == find(b))
        {
            cnt++;
        }
        else
        {
            dsu_union(a, b);
        }
    }

    cout << cnt << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int par[100005];
int group_sz[100005];
int cmp, mx;

int find(int node)
{
    if (par[node] == -1)
        return node;
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2)
{
    int leaderA = find(node1);
    int leaderB = find(node2);

    if (leaderA == leaderB)
        return;

    if (group_sz[leaderA] >= group_sz[leaderB])
    {
        par[leaderB] = leaderA;
        group_sz[leaderA] += group_sz[leaderB];
        mx = max(mx, group_sz[leaderA]);
    }
    else
    {
        par[leaderA] = leaderB;
        group_sz[leaderB] += group_sz[leaderA];
        mx = max(mx, group_sz[leaderB]);
    }
    cmp--;
};

int main()
{
    int n, e;
    cin >> n >> e;

    cmp = n;
    mx = 1;

    for (int i = 1; i <= n; i++)
    {
        par[i] = -1;
        group_sz[i] = 1;
    }

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        dsu_union(a, b);
        cout << cmp << " " << mx << endl;
    }

    return 0;
}
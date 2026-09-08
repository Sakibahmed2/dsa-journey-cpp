#include <bits/stdc++.h>
using namespace std;

char grid[205][205];
bool vis[205][205];
int n, m;

int main()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));

    


    return 0;
}
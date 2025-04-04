#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> ans;
vector<bool> vis;

bool yes = true;

void dfs(int u, int p)
{
    vis[u] = true;
    ans[u] = p;
    
    for (auto v : adj[u])
    {
        if (!vis[v])
        {
            dfs(v, 3 - p);
        }
        else if (ans[v] == ans[u])
        {
            yes = false;
            return;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    ans.resize(n, -1);
    vis.resize(n, false);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, 1);
        }
    }

    if (yes)
    {
        for (auto xd : ans)
        {
            cout << xd << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}

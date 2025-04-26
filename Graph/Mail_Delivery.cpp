#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<set<int>> graph;
vector<bool> vis;
vector<bool> visited;
vector<int> path;

void dfs(int u)
{
    vis[u] = true;
    for (auto v : graph[u])
    {
        if (!vis[v])
            dfs(v);
    }
}

bool Connected()
{
    vis.resize(n, false);
    dfs(0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            int degree = graph[i].size();
            if (degree > 1)
                return false;
        }
    }
    return true;
}

bool CheckEuler()
{
    if (!Connected())
        return false;
    int odd = 0;
    for (int i = 0; i < n; i++)
    {
        odd += (graph[i].size() & 1);
    }
    if (odd == 0 || odd == 2)
        return true;
    else
        return false;
}

void EulerPath(int u)
{
    visited[u] = true;

    while (!graph[u].empty())
    {
        int v = *graph[u].begin();
        graph[u].erase(v);
        graph[v].erase(u);
        EulerPath(v);
    }
    path.push_back(u);
}

int main()
{
    cin >> n >> m;
    visited.resize(n, false);
    graph.resize(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].insert(v);
        graph[v].insert(u);
    }

    if (!CheckEuler())
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        int start = 0;
        for (int i = 0; i < n; i++)
        {
            if (graph[i].size() % 2 == 1)
            {
                start = i;
                break;
            }
        }
        EulerPath(start);

        // EulerPath(0);

        int sz = 0;

        for (int i = 0; i < n; i++)
        {
            sz += (graph[i].size() > 0);
        }

        // cout << sz << endl;

        if (*path.begin() != path.back())
        {
            cout << "IMPOSSIBLE\n";
        }
        else if (sz > 0)
        {
            cout << "IMPOSSIBLE\n";
        }
        else
        {
            for (auto it : path)
                cout << it + 1 << " ";
            cout << endl;
        }
    }
}
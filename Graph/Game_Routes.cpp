#include <bits/stdc++.h>
using namespace std;

int n, m;
const int mod = 1e9+7;
vector<vector<int>> graph;
vector<int> dist;
vector<int> ans;
vector<bool> vis;

void dfs(int u) {
    vis[u] = true;
    for (auto v : graph[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
    ans.push_back(u); 
}

void MahavirCoder() {
    cin >> n >> m;
    graph.assign(n, {});
    dist.assign(n, 0);
    vis.assign(n, false);
    ans.clear();

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) dfs(i);
    }

    reverse(ans.begin(), ans.end());

    dist[0] = 1;

    for (auto u : ans) {
        for (auto v : graph[u]) {
            dist[v] = (dist[v] + dist[u])%mod;
        }
    }

    cout << dist[n - 1] << endl;
}

int main() {
    MahavirCoder();
    return 0;
}

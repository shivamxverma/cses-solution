#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> parent;
vector<bool> vis;

int ok = -1;

void dfs(int u, int par) {
    vis[u] = true;
    parent[u] = par;

    for (auto v : adj[u]) {
        if (v == par) continue;

        if (vis[v]) {
            ok = par;
            return;
        } else {
            dfs(v, u);
            if (ok != -1) return;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    parent.resize(n+1, -1);
    vis.resize(n, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, -1);
            if (ok != -1) break; 
        }
    }

    if (ok == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> ans;
        int path = ok;
        ans.push_back(ok + 1);

        while (parent[path] != ok) {
            path = parent[path];
            ans.push_back(path + 1);
        }
        ans.push_back(ok + 1);
        
        cout << ans.size() << endl;
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }

    return 0;
}

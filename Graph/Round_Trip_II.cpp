#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<bool> vis, ok;
vector<int> parent;

void adj(int n, int m) {
    graph.assign(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--; 
        graph[u].push_back(v); 
    }
}

vector<int> find_cycle(int u) {
    vis[u] = true;
    ok[u] = true;

    for (int v : graph[u]) {
        if (!vis[v]) {
            parent[v] = u;
            vector<int> cycle = find_cycle(v);
            if (!cycle.empty()) return cycle;
        } else if (ok[v]) {
            vector<int> cycle;
            cycle.push_back(v + 1);
            int curr = u;
            while (curr != v) {
                cycle.push_back(curr + 1);
                curr = parent[curr];
            }
            cycle.push_back(v + 1);
            reverse(cycle.begin(), cycle.end());
            return cycle;
        }
    }

    ok[u] = false;
    return {};
}

void MahavirCoder() {
    cin >> n >> m;
    graph.clear();
    vis.assign(n, false);
    ok.assign(n, false);
    parent.assign(n, -1);

    adj(n, m);

    vector<int> cycle;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            cycle = find_cycle(i);
            if (!cycle.empty()) break;
        }
    }

    if (cycle.empty()) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << cycle.size() << endl;
        for (int x : cycle) cout << x << " ";
        cout << endl;
    }
}

int main() {
    int t = 1;
    while (t--) {
        MahavirCoder();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;

vector<vector<int>> graph;
vector<bool> vis, ok;
vector<int> ans;
bool cycle;

bool dfs(int u, vector<vector<int>> &graph, vector<bool> &vis, vector<bool> &recStack, vector<int> &topo) {
    vis[u] = true;
    recStack[u] = true;

    for (int v : graph[u]) {
        if (!vis[v]) {
            if (dfs(v, graph, vis, recStack, topo)) return true;
        } else if (recStack[v]) {
            return true; 
        }
    }

    recStack[u] = false;
    topo.push_back(u);
    return false;
}


void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        graph[--u].push_back(--v);
    }

    vector<bool> vis(n, false), recStack(n, false);
    vector<int> topo;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (dfs(i, graph, vis, recStack, topo)) {
                cout << "IMPOSSIBLE\n";
                return;
            }
        }
    }

    reverse(topo.begin(), topo.end());
    vector<int> dist(n, -INF), parent(n, -1);
    dist[0] = 0;

    for (int u : topo) {
        for (int v : graph[u]) {
            if (dist[v] < dist[u] + 1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
            }
        }
    }

    if (dist[n - 1] == -INF) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<int> path;
    bool first = false;
    bool last = false;
    for (int cur = n - 1; cur != -1; cur = parent[cur]){
        if(cur+1==1)first = true;
        if(cur+1==n)last = true;
        path.push_back(cur);
    }

    if(!(first&last)){
        cout << "IMPOSSIBLE\n";
        return ;
    }
    
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for (int x : path) cout << x + 1 << " ";
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

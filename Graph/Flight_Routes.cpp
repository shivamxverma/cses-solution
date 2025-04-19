#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e18

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<vector<int>> dist(n + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    pq.push({0, 1});
    dist[1].push_back(0);

    while (!pq.empty()) {
        auto [curr_dist, node] = pq.top();
        pq.pop();

        for (auto [to, cost] : adj[node]) {
            int new_dist = dist[node].back() + cost;

            if (dist[to].size() < q) {
                dist[to].push_back(new_dist);
                pq.push({new_dist, to});
            } else if (new_dist < *max_element(dist[to].begin(), dist[to].end())) {
                auto it = max_element(dist[to].begin(), dist[to].end());
                *it = new_dist;
                pq.push({new_dist, to});
            }
        }
    }

    if (dist[n].size() < q) {
        cout << -1 << endl;
    } else {
        sort(dist[n].begin(), dist[n].end());
        for (int i = 0; i < q; i++) {
            cout << dist[n][i] << " ";
        }
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

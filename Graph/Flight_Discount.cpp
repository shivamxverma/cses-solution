#include <bits/stdc++.h>
using namespace std;

// Common Definitions
#define ll long long int
#define pb push_back
#define mp make_pair
#define endl "\n"
typedef pair<int, int> pi;
const ll INF = 1e18; // Use long long to avoid overflow

// Global Variables
int n, m;
vector<vector<pi>> graph; // Adjacency list: {vertex, weight}
vector<bool> mark;        // Visited array
vector<ll> dist;          // Distance array (long long for safety)

vector<vector<pi>> adj(int n, int m) {
    vector<vector<pi>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, l;
        cin >> u >> v >> l; // Input: u -> v with weight l
        u--, v--;           // Convert to 0-based indexing
        graph[u].emplace_back(v, l);
    }
    return graph;
}

void solve() {
    vector<bool> vis(n, false);
    // Priority queue: {distance, vertex, max_distance_so_far}
    priority_queue<tuple<ll, int, ll>, vector<tuple<ll, int, ll>>, greater<>> pq;

    dist[0] = 0; // Starting node
    pq.push({0, 0, 0}); // {distance, vertex, max_distance_so_far}

    while (!pq.empty()) {
        auto [d, u, m] = pq.top(); // d: current distance, u: vertex, m: max distance so far
        pq.pop();

        if (vis[u]) continue; // Skip if already visited
        vis[u] = true;

        for (auto [v, w] : graph[u]) {
            // Calculate new max distance considering the path to u
            ll new_m = max(m, dist[u]);
            // Custom cost: dist[u] - new_m + (new_m / 2) + w
            ll cost = dist[u] - new_m + (new_m / 2) + w;

            if (cost < dist[v]) {
                dist[v] = cost;
                pq.push({dist[v], v, new_m});
            }
        }
    }
}

void MahavirCoder() {
    cin >> n >> m;
    if (n <= 0 || m < 0) return;

    mark.resize(n, false);
    dist.resize(n, INF);
    graph = adj(n, m);
    solve();

    if (dist[n - 1] == INF) cout << "INF" << endl;
    else cout << dist[n - 1] << endl;
}

int main() {
    MahavirCoder();
    return 0;
}
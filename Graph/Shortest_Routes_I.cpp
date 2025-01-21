#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;  // Large number representing infinity
int n, m;
vector<vector<pair<int, int>>> graph;  // Adjacency list
vector<int> dist;  // Stores shortest distance from source

void adj(int n, int m) {
    graph.assign(n, vector<pair<int, int>>()); // Initialize graph
    for (int i = 0; i < m; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        u--, v--;  // Convert 1-based input to 0-based
        graph[u].push_back({v, l});
        graph[v].push_back({u, l});
    }
}

void dijkstra(int source) {
    dist.assign(n, INF); // Set all distances to INF
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source}); // Push source node with distance 0

    while (!pq.empty()) {
        auto [d, edge] = pq.top();
        pq.pop();

        if (d > dist[edge]) continue; // Ignore outdated entries

        for (auto [next, weight] : graph[edge]) {
            int newDist = dist[edge] + weight;
            if (newDist < dist[next]) {
                dist[next] = newDist;
                pq.push({newDist, next});
            }
        }
    }
}

void MahavirCoder() {
    cin >> n >> m;
    adj(n, m);  // Initialize the graph

    dijkstra(0);  // Run Dijkstra from node 0 (1st node in input)

    for (int d : dist) {
        cout << (d == INF ? -1 : d) << " ";  // Print -1 for unreachable nodes
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    MahavirCoder();
    return 0;
}

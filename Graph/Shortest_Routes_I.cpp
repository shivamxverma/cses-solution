#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// Common Definitions
#define int long long int
#define pb push_back
#define mp make_pair
#define endl "\n"
typedef pair<int, int> pi;
const int INF = 1e18;

int n, m;
vector<unordered_map<int, int>> graph;
vector<bool> mark;      
vector<int> dist; 

void solve() {
    vector<bool> vis(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[0] = 0; 
    pq.push({0,0});
    while (!pq.empty()) {
        auto [nn,dd] = pq.top(); 
        pq.pop();
        if(dd != dist[nn])continue;
        vis[nn] = true;
        for (auto [v, w] : graph[nn]) {
            int ddd = dist[nn] + w;
            if (ddd < dist[v]) {
                dist[v] = ddd;
                pq.push({v,dist[v]});
            }
        }
    }
}

void MahavirCoder() {
    cin >> n >> m;
    graph.resize(n);
    mark.resize(n, false);
    dist.resize(n, INF);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;  
 
        if (graph[u].count(v)) {
            graph[u][v] = min((int)graph[u][v], (int)w);
        } else {
            graph[u][v] = w; 
        }
    }

    solve();
    for(auto it : dist){
        cout << it << " ";
    }
    cout << endl;
}

signed main() {
    MahavirCoder();
    return 0;
}
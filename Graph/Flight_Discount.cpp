#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e18

vector<int> helper(int src,int n,vector<vector<pair<int,int>>> &adj){
    vector<int> dist(n+1,INF);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

    dist[src] = 0;

    pq.push({0,src});

    while(!pq.empty()){
        auto node = pq.top();
        pq.pop();

        int nn = node.second;
        int wt = node.first;

        if(dist[nn] < wt)continue;

        for(auto edge : adj[nn]){
            int to = edge.first;
            int cost = edge.second;
            int xx = cost + dist[nn];

            if(xx < dist[to]){
                dist[to] = xx;
                pq.push({dist[to],to});
            }
        }
    }
    return dist;
}

void solve() {

    int n,m;cin>>n>>m;

    vector<vector<pair<int,int>>> adj(n+1),adj_Rev(n+1);

    for(int i=0 ; i<m ; i++){
        int u,v,w;cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj_Rev[v].push_back({u,w});
    }

    vector<int> d = helper(1,n,adj);
    vector<int> d_ = helper(n,n,adj_Rev);

    int ans = INF;

    for(int i=1 ; i<=n ; i++){
        for(auto nn : adj[i]){
            int to = nn.first;
            int c = nn.second;
            if(d[i] == INF || d_[to] == INF)continue;
            
            ans = min(ans, d[i] + c/2 + d_[to]);
        }
    }

    cout << ans << endl;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

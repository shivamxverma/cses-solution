#include <bits/stdc++.h>
using namespace std;

#define int long long int

int n, m;
vector<vector<pair<int,int>>> graph;
vector<bool> vis;

int helper(int start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});
    int ans = 0;

    while(!pq.empty()){
        auto [wt, u] = pq.top();
        pq.pop();

        if(vis[u]) continue;
        vis[u] = true;
        ans += wt;

        for(auto [v, w] : graph[u]){
            if(!vis[v]) {
                pq.push({w, v});
            }
        }
    }

    return ans;
}

signed main() {
    cin >> n >> m;
    graph.resize(n);
    vis.assign(n, false);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int cnt = 0,ans = 0;
    
    for(int i=0 ; i<n ; i++){
        if(!vis[i]){
            ans = helper(0);
            cnt++;
        }
    }

    if(cnt>1)cout << "IMPOSSIBLE\n";
    else cout << ans << endl;

    return 0;
}

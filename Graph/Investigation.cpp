#include<bits/stdc++.h>
using namespace std;
const long long int INF = 1e17;

int n,m;
vector<vector<pair<int,int>>> graph;
vector<int> order;
vector<bool> vis,ok;
vector<long long> dist;
bool Cycle = false;

long long minimum_price(int u){
    dist.resize(n+1,INF);
    dist[u] = 0;

    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    pq.push({0,0});

    while(!pq.empty()){
        auto [wt,nn] = pq.top();
        pq.pop();

        if(dist[nn]<wt){
            continue;
        }

        for(auto [v,w] : graph[nn]){
            long long cost = dist[nn]+w;
            if(dist[v]>cost){
                dist[v] = cost;
                pq.push({dist[v],v});
            }
        }
    }

    return dist[n-1];
}

void topo(int u){
    vis[u] = true;
    ok[u] = true;

    for(auto [v,w] : graph[u]){
        if(!vis[v]){
            topo(v);
            if(Cycle)return;
        } else if(ok[v]){
            Cycle = true;
            return;
        }
    }
    ok[u] = false;
    order.push_back(u);
}


int main(){
    cin>>n>>m;
    graph.resize(n);
    vis.resize(n,false);
    ok.resize(n,false);
    for(int i=0 ; i<m ; i++){
        int u,v,w;cin>>u>>v>>w;
        u--,v--;
        graph[u].push_back({v,w});
    }
    int mn = minimum_price(0);
    topo(0);
    reverse(order.begin(),order.end());

    int routes = 0;
    vector<int> dp(n+1,0);
    vector<int> parent(n+1,-1);
    dp[0] = 1;
    
    for(auto u : order){
        for(auto [v, w] : graph[u]){
            if(v==n-1){
                if(dist[u]+w == dist[n-1])dp[v]+=dp[u];
            }else {
                dp[v]+=dp[u];
                parent[v] = u;
            }
        }
    }

    vector<int> count(n+1,INF);
    count[0] = 1;

    for(auto u : order){
        for(auto [v, w] : graph[u]){
            if (count[v] > count[u] + 1) {
                count[v] = count[u] + 1;
                parent[v] = u;
            }
        }
    }

    vector<int> path;
    bool first = false;
    bool last = false;
    for (int cur = n - 1; cur != -1; cur = parent[cur]){
        if(cur+1==1)first = true;
        if(cur+1==n)last = true;
        path.push_back(cur);
    }

    reverse(path.begin(), path.end());
 
    cout << path.size() << "\n";
    for (int x : path) cout << x + 1 << " ";
    cout << "\n";



    cout << dp[n-1] << endl;
    // for(auto i : dp)cout << i << endl;

}
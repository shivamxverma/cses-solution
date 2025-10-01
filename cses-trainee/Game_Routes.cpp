#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long int

const int mod = 1000000007;

// Method 1 For Game Routes

// int n,m;
// vector<bool> vis;
// vector<vector<int>> graph;
// vector<ll> routes;

// ll dfs(int u){
//     if (u == n - 1) return 1;
//     if (vis[u]) return routes[u];
//     vis[u] = true;

//     ll ways = 0;
//     for(auto v : graph[u]){
//         ways = (ways + dfs(v))%mod;
//     }
//     return routes[u] = ways;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin >> n >> m;
//     vis.resize(n,false);
//     graph.resize(n);
//     routes.resize(n,0);
//     routes[0] = 1;
//     for (int i = 0; i < m; i++)
//     {
//         int u,v;cin >> u >> v;
//         u--, v--;
//         graph[u].push_back(v);
//     }

//     cout << dfs(0) << endl;
// }


// Method 2 Solve this Problem


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> graph(n);
//     vector<ll> routes(n,0);
//     vector<int> indeg(n,0);
//     routes[0] = 1;
//     for (int i = 0; i < m; i++)
//     {
//         int u,v;cin >> u >> v;
//         u--, v--;
//         graph[u].push_back(v);
//         indeg[v]++;
//     }
 
//     queue<int> q;
 
//     for(int i=0 ; i<n ; i++){
//         if(indeg[i] == 0){
//             q.push(i);
//         }
//     }
 
//     while (!q.empty())
//     {
//         int u = q.front();
//         q.pop();
//         for (int v : graph[u])
//         {
//             indeg[v]--;
//             routes[v] = (routes[v] + routes[u])%mod;
//             if(indeg[v] == 0)q.push(v);
//         }
//     }
//     cout << routes[n-1]%mod << endl;
// }


// Method 3 Solve this Problem Using topological order + interative dp

// int n,m;
// vector<bool> vis;
// vector<vector<int>> graph;
// vector<int> order;

// void dfstopo(int u){
//     vis[u] = true;

//     for(auto v : graph[u]){
//         if(!vis[v])dfstopo(v);
//     }
//     order.push_back(u);
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin >> n >> m;
//     graph.resize(n);
//     vis.resize(n,false);
//     for (int i = 0; i < m; i++)
//     {
//         int u,v;cin >> u >> v;
//         u--, v--;
//         graph[u].push_back(v);
//     }

//     for(int i=0 ; i<n ; i++){
//         if(!vis[i])dfstopo(i);
//     }

//     reverse(order.begin(),order.end());

//     vector<ll> dp(n,0);

//     dp[0] = 1;

//     for(auto u : order){
//         for(auto v : graph[u]){
//             dp[v] = (dp[v] + dp[u])%mod;
//         }
//     }

//     cout << dp[n-1] << endl;
// }

struct State {
    long long cost;
    long long minEdge;
    int node;
    bool operator<(const State& other) const {
        return cost > other.cost; 
    }
};

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) { 
        int n = online.size();
        vector<vector<pair<int,long long>>> graph(n);

        vector<int> indeg(n,0);

        for(auto& ed : edges){
            if(online[ed[0]] && online[ed[1]]){
               graph[ed[0]].push_back({ed[1],ed[2]});
               indeg[ed[1]]++;
            }
        }

        vector<long long> Cost(n,INT_MAX);
        vector<long long> dist(n,-1);
        queue<int> pq;
        
        dist[0] = LLONG_MAX;
        Cost[0] = 0;

        for(int i=0 ; i<n ; i++){
            if(indeg[i] == 0)pq.push(i);
        }


        while(!pq.empty()){
            int u = pq.front();
            pq.pop();

            for(auto [v,w] : graph[u]){
                indeg[v]--;
                long long newCost = w+Cost[u];
                if (newCost > k) continue;
                long long newMinCost = min(dist[u],w);
                dist[v] = newMinCost;
                if(indeg[v] == 0)pq.push(v);
            }
        }

        return dist[n-1];

    }
};

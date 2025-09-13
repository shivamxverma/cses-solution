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

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
#define ll long long int

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> graph(n);
    
    for (int i = 0; i < m; i++)
    {
        int u, v,w;
        cin >> u >> v >> w;
        u--, v--;
        graph[u].push_back({v,w});
    }
    
    vector<int> parent(n,-1);
    vector<ll> dist(n,LLONG_MAX);
    queue<pair<ll,int>> pq;
    vector<bool> vis(n,false);
    vis[0] = true;
    dist[0] = 0;
    pq.push({0,0}); // [cost,node]
    int start = -1;

    while(!pq.empty()){
        auto [cost,u] = pq.front();
        pq.pop();
        if(dist[u] < cost)continue;

        for(auto [v,w] : graph[u]){
            ll newCost = cost+w;
            if(vis[v]){
                start = v;
                continue;
            }

            if(dist[v] > newCost){
                dist[v] = newCost;
                parent[v] = u;
                pq.push({newCost,v});
            } 
        }
    }

    cout << start << endl;

    for(auto it : parent)cout << it << " ";
    cout << endl;   
}
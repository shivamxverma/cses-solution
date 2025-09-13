#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

#define ll long long int

vector<vector<pair<int, ll>>> graph;
vector<ll> dist;

void ShortestPath(int src)
{
    vector<bool> vis(graph.size(), false);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        auto [wt, node] = pq.top();
        pq.pop();
        if (vis[node])
            continue;
        vis[node] = true;

        if(dist[node] < wt)continue;

        for (auto [v, W] : graph[node])
        {
            ll newW = wt + W;
            if (dist[v] > newW)
            {
                dist[v] = newW;
                pq.push({newW, v});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    dist.resize(n, LLONG_MAX);
    graph.resize(n);
    int u, v;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--, v--;
        graph[u].push_back({v,w});
    }

    ShortestPath(0);
    for(auto it : dist) cout << it << " ";
    cout << endl;
}
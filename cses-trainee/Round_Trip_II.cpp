#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

#define ll long long int

int n, m;
vector<vector<int>> graph;
vector<int> parent;
vector<bool> ok;
vector<bool> vis;

int start = -1;

void Solve(int u){
    vis[u] = true;
    ok[u] = true;
    for(auto v : graph[u]){
        if(!vis[v]){
            parent[v] = u;
            Solve(v);
            if(start != -1)return;
        } else if(ok[v]){
            start = v;
            parent[v] = u;
            return ;
        }
    }
    ok[u] = false;
}

int main()
{
    
    cin >> n >> m;
    graph.resize(n);
    parent.resize(n, -1);
    vis.resize(n,false);
    ok.resize(n,false);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
    }

    for(int i=0 ; i<n ; i++){
        if(!vis[i]){
            Solve(i);
        }
        if(start != -1)break;
    }

    if(start == -1){
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> path;
        path.push_back(start+1);

        for(int p = parent[start] ; p != start && p != -1 ; p = parent[p]){
            path.push_back(p+1); 
        }
        
        path.push_back(start+1);

        reverse(path.begin(), path.end());

        cout << path.size() << endl;
        for(auto it : path) cout << it << " ";
        cout << endl;
        // cout << "YES\n";
    }
}
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

const int N = 1e5+5;
vector<int> adj[N];
vector<bool> vis(N, false);
vector<int> parent(N, -1);
int n, m;
int yes = -1;

bool Solve(int u, int p){
    vis[u] = true;
    for(auto v : adj[u]){
        if(!vis[v]){
            parent[v] = u;
            if(Solve(v, u)) return true;
        } else if(v != p){
            yes = v;
            parent[v] = u;
            return true;
        }
    }
    return false;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool cycle = false;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            if(Solve(i, -1)){
                cycle = true;
                break;
            }
        }
    }

    vector<int> path;

    for(int i = parent[yes] ; parent[yes]!=yes ; i = parent[yes]){
        cout << i << " ";
    }
    cout << endl;
}

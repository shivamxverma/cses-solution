#include<bits/stdc++.h>
#include<iostream>
using namespace std;

const int N = 1e5+5;
vector<int> adj[N];
vector<bool> vis(N, false);
vector<int> parent(N, -1);
int n, m;
int yes = -1;

void Solve(int u, int p){
    vis[u] = true;
    for(auto v : adj[u]){
       if(vis[v]){
        if(u != p)yes = u+1;
        
        if(yes != -1)return ;
       }
       parent[v] = u;
       Solve(v,u);
    }
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

    Solve(0,-1);

    if(yes == -1){
        cout << "IMPOSSIBLE\n";
    }

    vector<int> path;
    for (int i = yes; i != -1; i = parent[i]) {
        path.push_back(i);
    }
    path.push_back(yes);

    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    for(auto it : path)cout << it+1 << " ";
    cout << endl;
}

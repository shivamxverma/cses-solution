#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;

int n,m;
vector<vector<int>> graph;
vector<bool> vis;
vector<int> parent;
vector<bool> ok;
 
vector<vector<int>> adj(int n,int m){
  vector<vector<int>> graph(n);
  for(int i=0 ; i<m ; i++){
    int u,v;cin>>u>>v;
    u--,v--;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  return graph;
}
 
int yes = -1;
 
void dfs(int u) {
    vis[u] = true;
    ok[u] = true;
 
    for (int v : graph[u]) {
        if (!vis[v]) {
            dfs(v);
            parent[v] = u;
            if (yes!=-1) return;
        } else if (ok[v]) {
            parent[v] = u;
            yes = u;
            return;
        }
    }
 
    ok[u] = false;
}
 
 
void MahavirCoder(){
  cin>>n>>m;
  graph.resize(n),parent.resize(n,-1),vis.resize(n,false),ok.resize(n,false);
  graph = adj(n,m);

  for(int i=0 ; i<n ; i++){
    if(!vis[i]){
        dfs(i);
        if(yes==-1){
            break;
        }
    }
  }

  if(yes!=-1){
    vector<int> ans;
    int path = yes;
    ans.push_back(yes+1);
    while(parent[path] != yes){
        ans.push_back(parent[path]+1);
        path = parent[path];
    }
    ans.push_back(yes+1);
    cout << ans.size() << endl;
    for(auto it : ans)cout << it << " ";
    cout << endl;
  }
  else {
    cout << "IMPOSSIBLE\n";
  }
}
 
int main(){
    int t = 1;
    // cin>>t;
    while(t--){
        MahavirCoder();
    }
}

#include<bits/stdc++.h>
using namespace std;

vector<int> fvis;

void dfs(int u,vector<bool> &vis,vector<vector<int>> graph){
  vis[u] = true;
  for(auto v : graph[u]){
    if(vis[v])continue;
    dfs(v,vis,graph);
  }
}

int main (){
  int n,m;cin>>n>>m;

  vector<vector<int>> graph(n);

  for(int i=0 ; i<m ; i++){
    int u,v;cin>>u>>v;
    u--,v--;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  vector<bool> vis(n,false);
  
  for(int i=0 ; i<n ; i++){
    if(!vis[i]){
      fvis.push_back(i+1);
      dfs(i,vis,graph);
    }
  }

  cout << fvis.size()-1 << endl;

  for(int i=0 ; i<fvis.size()-1 ; i++){
     cout << fvis[i] << " " << fvis[i+1] << endl;
  }
  cout << endl;

  return 0;

}
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<bool> vis,ok;
bool cycle = false;
vector<int> ans;

void dfs(int u){
    vis[u] = true;
    ok[u] = true;

    for(auto v : graph[u]){
        if(!vis[v]){
            dfs(v);
            if(cycle)return;
        } else if(ok[v]){
            cycle = true;
            return;
        }
    }
    ok[u] = false;
    ans.push_back(u);
}


int main() {
    cin >> n >> m;
    graph.resize(n);
    vis.assign(n, false);
    ok.assign(n, false);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--; 
        graph[u].push_back(v); 
    }

    for(int i=0 ; i<n ; i++){
        dfs(i);
        if(cycle)break;
    }

    if(!cycle){
        reverse(ans.begin(),ans.end());
        for(auto x : ans)cout << x << " ";
        cout << endl;
    } else {
        cout << "IMPOS\n";
    }


    return 0;
}

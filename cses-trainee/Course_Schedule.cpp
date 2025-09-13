#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

#define ll long long int

vector<vector<int>> graph;
vector<int> color;
vector<int> order;

bool dfs(int u){
    color[u] = 1;
    for(auto v : graph[u]){
        if(color[v] == 1)return false;
        if(color[v] == 0 && !dfs(v))return false;
    }
    color[u] = 2;
    order.push_back(u+1);
    return true;
}

int main()
{
    int n,m;
    cin >> n >> m;
    graph.resize(n);
    color.resize(n);
    
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
    }

    for(int i=0 ; i<n ; i++){
        if(color[i] == 0){
            bool yes = dfs(i);
            if(!yes){
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    reverse(order.begin(),order.end());
   
    for(auto p : order)cout << p << " ";
    cout << endl;
}
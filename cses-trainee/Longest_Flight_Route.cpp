#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long int


vector<vector<int>> graph;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    graph.resize(n);
    vector<int> indeg(n,0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        indeg[v]++;
    }

    queue<int> play;
    vector<int> dist(n,INT_MIN);
    dist[0] = 0;
    play.push(0);

    for(int i = 1 ; i<n ; i++){
        if(indeg[i] == 0)play.push(i);
    }

    vector<int> parent(n,-1);

    while(!play.empty()){
        int u = play.front();
        play.pop();

        for(auto v : graph[u]){
            indeg[v]--;
            if(indeg[v] == 0){
                play.push(v);
            }
            if(dist[v] < dist[u]+1){
                dist[v] = dist[u]+1;
                parent[v] = u;
            }
        }
    }

    vector<int> path;
    
    int p = n-1;
    while (p != -1) {
        path.push_back(p+1);
        p = parent[p];
    }
    
    reverse(path.begin(), path.end());
    
    if (path.front() != 1 || path.back() != n) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    cout << path.size() << endl;
    
    for(auto it : path) cout << it << " ";
    cout << endl;

}
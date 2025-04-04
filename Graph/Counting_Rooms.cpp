#include<bits/stdc++.h>
using namespace std;

bool isValid(int x,int y,vector<vector<bool>> &vis,vector<string> &graph){
    int n = graph.size();
    int m = graph[0].size();
    return x>=0 && x<n && y>=0 && y<m && !vis[x][y] && graph[x][y]!='#';
}

vector<pair<int,int>> dir = {{0,-1},{0,1},{1,0},{-1,0}};

void dfs(int i,int j,vector<vector<bool>> &vis,vector<string> &graph){
    vis[i][j] = true;
    for(auto [dx,dy] : dir){
        int nx = dx + i;
        int ny = dy + j;
        if(isValid(nx,ny,vis,graph)){
           dfs(nx,ny,vis,graph);
        }
    }
}

int main (){

    int n,m,ans = 0;
    cin>>n>>m;

    vector<string> graph(n);
    for(int i=0 ; i<n ; i++){
        cin>>graph[i];
    }
    
    vector<vector<bool>> vis(n,vector<bool> (m,false));


    for(int i=0 ; i<n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(!vis[i][j] && graph[i][j]!='#'){
                dfs(i,j,vis,graph);
                ans++;
            }
        }
    }

    cout << ans << endl;
}
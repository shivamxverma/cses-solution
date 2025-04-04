#include<bits/stdc++.h>
using namespace std;

vector<string> adj;
vector<vector<bool>> vis;

bool isValid(int x,int y){
    int n = adj.size();
    int m = adj[0].size();
    return x>=0 && x<n && y>=0 && y<m && adj[x][y]!='#';
}

vector<pair<int, pair<int, char>>> dir = {
    {0, {-1, 'L'}}, {0, {1, 'R'}}, {1, {0, 'D'}}, {-1, {0, 'U'}}
};

void dfs(int i,int j,int d){
    vis[i][j] = true;

    for(auto it : dir){
        int nx = it.first + i;
        int ny = it.second.first + j;
        
        if(isValid(nx,ny)){
            dfs(nx,ny,d+1);
        }
    }
}

int main (){
    int n,m;
    adj.resize(n);
    vis.assign(n,vector<bool>(m,false));
    for(int i=0 ; i<n ; i++){
        cin>>adj[i];
    }


}
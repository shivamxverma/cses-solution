#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
#define ll long long int

int main()
{
    int n,m;cin>>n>>m;
    vector<string> grid(n);
    for(int i=0 ; i<n ; i++){
        cin>>grid[i];
    }
    vector<pair<int,int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};


    queue<pair<int,int>> pq;
    pq.push({0,0});

    while(!pq.empty()){
        
    }

    // for(int i=0 ; i<n ; i++){
    //     for(int j = i+1 ; j<m ; j++){
    //         bool isEqual = false;
    //         vector<bool> vis(4,0);
    //         for(auto [dx,dy] : dir){
    //             int nx = i+dx,ny = j+dy;
    //             if(nx>=0 && nx<n && ny>=0 && ny<m){
    //                int chr = grid[nx][ny] - 'A';
    //                vis[chr] = true;
    //                if(grid[i][j] == grid[nx][ny])isEqual = true;
    //             }
    //         }

    //         bool impossible = true;

    //         if(isEqual){
    //             for(auto eq : vis){
    //                 if(!eq){
    //                     impossible = false;
    //                     grid[i][j] = eq + 'A';
    //                 }
    //             }
    //         }

    //         if(impossible){
    //             cout << "IMPOSSIBLE\n";
    //             return 0; 
    //         }

    //     }
    // }
}
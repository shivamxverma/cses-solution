#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

#define ll long long int

int main()
{
    int n, m,q;
    cin >> n >> m >> q;
    vector<vector<ll>> graph(n,vector<ll>(n,LLONG_MAX));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--, v--;
        graph[u][v] = min(graph[u][v],w);
        graph[v][u] = min(graph[v][u],w);
    }

    vector<vector<ll>> dp(n,vector<ll>(n,LLONG_MAX));

    
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(i == j)dp[i][j] = 0;
            else if(graph[i][j] != LLONG_MAX)
                dp[i][j] = graph[i][j];
        }
    }

    for(int k = 0 ; k < n ; k++){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(dp[i][k] < LLONG_MAX && dp[k][j] < LLONG_MAX)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }


    while(q--){
        int u,v;cin>>u>>v;
        u--,v--;

        if(dp[u][v] == LLONG_MAX)cout << -1 << endl;
        else cout << dp[u][v] << endl;
    }
}
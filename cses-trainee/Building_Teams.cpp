// Jay Shree Ram
// Shivam Verma

#include <bits/stdc++.h>
#include <iostream>

using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
vector<bool> vis(N, false);
int n, m;
vector<int> ans(N);

bool Solve(int u, int t)
{
    vis[u] = true;
    ans[u] = t;
    for (auto v : adj[u])
    {
        if (!vis[v])
        {
            if (!Solve(v, 3 - t))
                return false;
        }
        else if (ans[v] == ans[u])
        {
            return false;
        }
    }
    return true;
}

void MahavirCoder()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    bool possible = true;

    for(int i=0 ; i<n ; i++){
        if(!vis[i]){
            possible &= Solve(i,1);
        }
    }
    if(possible){
        for(int i=0 ; i<n ; i++)cout << ans[i] << " ";
        cout << endl;
    } else cout << "IMPOSSIBLE\n";
}

int main()
{
    int t = 1;
    // cin>>t;
    while (t--)
    {
        MahavirCoder();
    }
}
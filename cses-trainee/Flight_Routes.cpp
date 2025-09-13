// Jai shree Ram
// Shivam verma

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <set>
#include <map>
using namespace std;

// some common Defination

const long long INF = LLONG_MAX;
#define ll long long int
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define vc vector<ll>
typedef pair<int, int> pi;
const int mod = 1000000007;
const int N = 1e3 + 5;
#define endl "\n"
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define loop(i, a, b) for (int i = a; i < b; i++)
#define Loop(i, b) for (int i = 0; i < b; i++)
#define Rloop(i, a, b) for (int i = a; i >= b; i--)
#define print(str) cout << str << "\n"

int n,m,k;
vector<vector<pair<int,int>>> graph;
vector<vector<int>> dist;
vector<bool> ok;

void dfs(int u,ll ww){
    ok[u] = true;

    for(auto [v,w] : graph[u]){
        if(!ok[v]){
            dist[v].push_back(ww+w);
            dfs(v,ww+w);
        }
    }

    ok[u] = false;
}

void MahavirCoder()
{
    cin>>n>>m>>k;
    ok.resize(n,false);
    graph.resize(n);
    dist.resize(n);
    for(int i=0 ; i<m ; i++){
        int u,v,w;cin>>u>>v>>w;
        u--,v--;
        graph[u].push_back({v,w});
    }

    dfs(0,0);

    sort(dist[n-1].begin(),dist[n-1].end());

    for(int i=0 ; i<k ; i++)cout << dist[n-1][i] << " ";
    cout << endl;

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
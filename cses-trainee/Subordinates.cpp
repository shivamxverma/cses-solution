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
const int N = 2e5+5;
#define endl "\n"
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define loop(i, a, b) for (int i = a; i < b; i++)
#define Loop(i, b) for (int i = 0; i < b; i++)
#define Rloop(i, a, b) for (int i = a; i >= b; i--)
#define print(str) cout << str << "\n"

vector<int> adj[N];
int Sub[N];
vector<bool> Visited;
int n;

void Solve(int u){
    Visited[u] = true;
    for(auto v : adj[u]){
        if(!Visited[v]){
            Solve(v);
            Sub[u] += 1+Sub[v];
        }
    }
}

void MahavirCoder()
{
    cin>>n;
    Visited.resize(n+1,false);
    for(int i=2 ; i<=n ; i++){
        int x;cin>>x;
        adj[x].push_back(i);
    }
    Solve(1);
    for(int i=1 ; i<=n ; i++)cout << Sub[i] << " ";
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
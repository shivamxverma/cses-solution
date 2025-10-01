// Jai shree Ram
// Shivam verma

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
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
const int N = 1e5;
#define endl "\n"
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sloop(i, a, b) for (int i = a; i < b; i++)
#define loop(i, b) for (int i = 0; i < b; i++)
#define rloop(i, a, b) for (int i = a; i >= b; i--)
#define print(str) cout << str << "\n"

// Inbuilt Function

#define sum(a) (accumulate((a).begin(), (a).end(), 0LL))
#define unique_el(s) \
    sort(all(s));    \
    s.erase(unique(s.begin(), s.end()), s.end())
#define minel(a) (*min_element((a).begin(), (a).end()))
#define maxel(a) (*max_element((a).begin(), (a).end()))
#define mini(a) (min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a) (max_element((a).begin(), (a).end()) - (a).begin())
#define cnt(a, x) (count((a).begin(), (a).end(), (x)))
#define lob(a, x) (lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define upb(a, x) (upper_bound((a).begin(), (a).end(), (x)) - (a).begin())


void MahavirCoder() {
    int n,m;cin>>n>>m;
    vector<vector<pair<int,ll>>> graph(n);
    loop(i,m){
        int u,v,w;cin>>u>>v>>w;
        u--,v--;
        graph[u].push_back({v,w});
    }

    vector<ll> dist(n,LLONG_MAX);
    vector<ll> ways(n,0);
    vector<int> minFlights(n,INT_MAX);
    vector<int> maxFlights(n,INT_MAX);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    dist[0] = 0;
    pq.push({0,0}); 
    ways[0] = 1;
    minFlights[0] = 0;
    maxFlights[0] = 0;

    while(!pq.empty()){
        auto [cost,u] = pq.top();
        pq.pop();

        if(dist[u] < cost) continue;

        for(auto [v,w] : graph[u]){
            ll newcost = cost + w;

            if(dist[v] > newcost){
                dist[v] = newcost;
                ways[v] = ways[u];
                minFlights[v] = minFlights[u] + 1;
                maxFlights[v] = maxFlights[u] + 1;
                pq.push({newcost,v});
            } else if(dist[v] == newcost){
                ways[v] = (ways[u] + ways[v])%mod;
                minFlights[v] = min(minFlights[v], minFlights[u] + 1);
                maxFlights[v] = max(maxFlights[v], maxFlights[u] + 1);
            }
        }
    }

    
    if (dist[n - 1] == INF) {
        cout << -1 << endl; 
        return;
    }

    cout << dist[n - 1] << " " << ways[n - 1] << " " 
         << minFlights[n - 1] << " " << maxFlights[n - 1] << endl;
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
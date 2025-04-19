#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e18

struct Edge {
    int a,b,cost;
};

void solve(){
    int n , m;cin>>n>>m;
    vector<int> d(n+1,0);
    vector<int> p(n+1,-1);
    int x = -1;

    vector<Edge> edges(n);

    for(int i=0 ; i<m ; i++){
        int u,v,w;cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }

    for(int i=0 ; i<n ; i++){
        x = -1;
        for (Edge e : edges) {
            if (d[e.a] + e.cost < d[e.b]) {
                d[e.b] = max((int)-INF, d[e.a] + e.cost);
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
    } else {
        for (int i = 0; i < n; ++i)
            x = p[x];

        vector<int> cycle;
        for (int v = x;; v = p[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "YES\n";
        for (int v : cycle)
            cout << v << ' ';
        cout << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
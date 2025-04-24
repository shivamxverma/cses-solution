#include <bits/stdc++.h>
using namespace std;

int mx = 1;

class DSU {
    vector<int> sz;
    vector<int> parent;
public:
    DSU(int n) {
        sz.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }

    int findpar(int u) {
        if (u == parent[u]) return u;
        return parent[u] = findpar(parent[u]);
    }

    bool unite(int u, int v) {
        int pu = findpar(u);
        int pv = findpar(v);

        if (pu == pv) return 0;

        if (sz[pu] < sz[pv]) swap(pu, pv);

        parent[pv] = pu;
        sz[pu] += sz[pv];
        mx = max(mx,sz[pu]);

        return sz[pu];
    }
};

int main(){
    int n,m;cin>>n>>m;
    DSU dsu(n);

    int compo = n;
    for(int i=0 ; i<m ; i++){
        int u,v;cin>>u>>v;
        int ok = dsu.unite(u,v);
        if(ok!=0){
            compo--;
        }
        cout << compo << " " << mx << endl;
    }
}

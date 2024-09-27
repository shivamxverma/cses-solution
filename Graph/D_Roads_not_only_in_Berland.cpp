#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pb push_back
#define endl "\n"
#define rep(i,a,b) for (int i = a; i < b; i++)

class DSU {
    vector<int> parent;
    vector<int> size;
    vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        rank.assign(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findpar(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findpar(parent[node]);
    }

    void findunion(int u, int v) {
        int pu = findpar(u);
        int pv = findpar(v);
        if (pu == pv) return;

        if (size[pu] > size[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        } else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};

void solve() {
    int n;
    cin >> n;
    DSU d(n);

    vector<pair<int, int>> oldroad;
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (d.findpar(u) == d.findpar(v)) {
            oldroad.pb({u, v});
        } else {
            d.findunion(u, v);
        }
    }

    set<int> st;
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        int parent = d.findpar(i);
        if (st.find(parent) == st.end()) {
            st.insert(parent);
            temp.pb(parent);
        }
    }

    cout << temp.size() - 1 << endl;
    
    for (int i = 0; i < temp.size() - 1; i++) {
        cout << oldroad[i].first + 1 << " " << oldroad[i].second + 1 << " " 
             << temp[i] + 1 << " " << temp[i+1] + 1 << endl;
    }
}

signed main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}

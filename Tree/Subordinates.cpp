#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define int long long
vector<vector<int>> tree;
vector<int> ans;
void dfs(int uu) {
    ans[uu] = 1;
    for(auto vv : tree[uu]) {
        dfs(vv);
        ans[uu] += ans[vv];
    }
}
void solve() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    v[1] = 0;
    for(int i = 2; i <= n; i++) {
        cin >> v[i];
    } 
    tree.resize(n + 1);
    ans.resize(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        int u = i;
        int v_ = v[i];
        tree[v_].push_back(u);
    }
    dfs(0); 
    for(int i = 1; i <= n; i++) {  
        cout << ans[i] << " ";  
    }
    cout << endl;
}
signed main() {
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define vi vector<int>
typedef pair<int,int> pi;
#define setbits(x) __builtin_popcountll(x)
#define binary_rep(x) bitset<sizeof(10)*8> binary_rep(x)
const int M = 1000000007;
#define endl "\n" 
#define sum(a) (accumulate((a).begin(), (a).end(), 0LL))
#define unique_el(s) sort(all(s)) ; s.erase(unique(s.begin(), s.end()), s.end())
#define minel(a) (*min_element((a).begin(), (a).end()))
#define maxel(a) (*max_element((a).begin(), (a).end()))
#define mini(a) (min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a) (max_element((a).begin(), (a).end()) - (a).begin())
#define cnt(a, x) (count((a).begin(), (a).end(), (x)))
#define lob(a, x) (lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define upb(a, x) (upper_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (int i = a; i < b; i++)
#define Rep(i,b) for (int i = 0; i < b; i++)
#define repr(i,a,b) for (int i = a; i >= b; i--)
#define printyes cout << "YES" << "\n" 
#define printno cout << "NO" << "\n" 
 
#ifndef ONLINE_JUDGE
#define debug(x) cout << #x <<" "; _print(x); cout << endl;
#else
#define debug(x)
#endif
template <class T> void _print(T t){cout<<t;}
template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.first); cout << ","; _print(p.second); cout << "}";}
template <class T> void _print(vector <T> v) {for (T i : v) {_print(i); cout << " ";}}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(unordered_set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(unordered_multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
 
template <class T> istream & operator>> (istream &in, vector<T> &v) {
    for (auto &vl : v) { in >> vl;} return in; }
template <typename T> void pvec(vector<T>&v) {
    for(auto i : v) {cout << i << " ";} cout << endl;}

vector<int> ans;
int realnode = 0;
int max_depth = -1;
int max_depth1 = -1;
int dfs(vector<vector<int>> &tree, int node, vector<bool> &vis, int depth) {
    vis[node] = true;
    if (depth > max_depth) {
        max_depth = depth;
        realnode = node;
    }
    for (auto i : tree[node]) {
        if (!vis[i]) {
            dfs(tree, i, vis, depth + 1);
        }
    }
    return depth;
}

int dfs1(vector<vector<int>> &tree, int node, vector<bool> &vis, int depth) {
    vis[node] = true;
    if (depth > max_depth1) {
        max_depth1 = depth;
    }

    int maxi = 0;
    for (auto i : tree[node]) {
        if (!vis[i]) {
            dfs(tree, i, vis, depth + 1);
        }
    }
    return depth;
}

int dfs2(vector<vector<int>> &tree,int node,vector<bool> &vis,int depth){
    
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> tree(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<bool> vis(n,false);
    dfs(tree, 0, vis, 0);
    vector<bool> vis1(n,false);
    dfs1(tree,realnode,vis1,0);
    int diameter = max_depth+max_depth1;

    vector<int> ans(n+1,-1);
    for(int i=0 ; i<n ; i++){
        if(tree[i].size() == 1)ans[i+1] = diameter;
        else ans[i+1] = diameter-1;
    }
    for(int i=1 ; i<=n ; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

signed main(){
    int t = 1;
    while(t--){
        solve();
    }
}
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
 
#define int long long
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
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
template <class T> void _print(T t){cerr<<t;}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
 
template <class T> istream & operator>> (istream &in, vector<T> &v) {
    for (auto &vl : v) { in >> vl;} return in; }
template <typename T> void pvec(vector<T>&v) {
    for(auto i : v) {cout << i << " ";} cout << endl;}

int yes = -1;

void dfs(int i, vector<int> g[], vector<bool> &vis, vector<int> &parent) {
    vis[i] = true;
    for (auto xd : g[i]) {
        if (vis[xd]) {
            if (parent[i] == xd) continue;
            yes = i;
            parent[xd] = i;
            return;
        }
        if (!vis[xd]) {
            parent[xd] = i;
            dfs(xd, g, vis, parent);
            if (yes != -1) return;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> g[n];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<bool> vis(n, false);
    vector<int> parent(n, -1);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, g, vis, parent);
            if (yes != -1) break;
        }
    }

    if (yes == -1)
        cout << "IMPOSSIBLE" << endl;
    else {
        vector<int> res;
        int start = yes, end = yes;
        res.push_back(end);

        while (parent[end] != start) {
            res.push_back(parent[end]);
            end = parent[end];
        }
        res.push_back(start);
        cout << res.size() << endl;
        for (int x : res) {
            cout << x + 1 << " ";
        }
        cout << endl;
    }
}

signed main(){
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
}
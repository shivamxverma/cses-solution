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

void shortest_distance(vector<vector<int>>& g) {
    int n = g.size();

    // Replace -1 with a large value, and set diagonal to 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] == -1) {
                g[i][j] = 1e9;  // Large value for no direct edge
            }
            if (i == j) g[i][j] = 0;  // Distance to itself is zero
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    // Set unreachable distances back to -1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] == 1e9) {
                g[i][j] = -1;
            }
        }
    }
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    // Create a graph initialized to -1 (no edge)
    vector<vector<int>> graph(n, vector<int>(n, INT_MAX));

    // Input edges
    for (int i = 0; i < m; i++) {
        int x, y, wt;
        cin >> x >> y >> wt;
        x--, y--;  // Convert to 0-based indexing
        graph[x][y] = wt;
        graph[y][x] = wt;
    }

    // Find all-pairs shortest distances
    shortest_distance(graph);

    // Answer queries
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;  // Convert to 0-based indexing
        cout << graph[x][y] << endl;
    }
}
signed main(){
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
}
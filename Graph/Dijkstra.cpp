#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
 
#define int long long
#define aint(v) (v).begin(), (v).end()
#define raint(v) (v).rbegin(), (v).rend()
#define vi vector<int>
typedef pair<int,int> pi;
#define setbits(x) __builtin_popcountint(x)
#define binary_rep(x) bitset<sizeof(10)*8> binary_rep(x)
const int M = 1000000007;
#define endl "\n" 
#define sum(a) (accumulate((a).begin(), (a).end(), 0int))
#define unique_el(s) sort(aint(s)) ; s.erase(unique(s.begin(), s.end()), s.end())
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

void Dijkstra(int s, int n, vector<int> &dist,vector<pair<int, int>> *adj) {
	dist[s] = 0;
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({0, s});
	while (!q.empty()) { // O(n)
		pair<int, int> here = q.top();
		q.pop();
		int v = here.ss;
		int d_v = here.ff;
		if (d_v != dist[v])
			continue;
		for (auto edge : adj[v]) { // O(m)
			if (dist[v] + edge.ss < dist[edge.ff]) {
				dist[edge.ff] = dist[v] + edge.ss;
				q.push({dist[edge.ff], edge.ff});
			}
		}
	} 
    // O(nlogn + mlog(n)) = O((n+m)log(n))
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    
    for (int i = 0; i < m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        x--, y--; 
        g[x].push_back({y, c}); 
        g[y].push_back({x, c}); 
    }
    
    int s; 
    cin >> s;
    s--; 
    
    vector<int> dist(n, INT_MAX);
    
    Dijkstra(s, n,dist,g);
    
    for (int i = 0; i < n; i++) {
        cout << "Distance from node " << s + 1 << " to node " << i + 1 << " is " << dist[i] << endl;
    }
}


signed main(){
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
}

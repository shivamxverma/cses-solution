#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
 
#define int long long
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define vi vector<bool>
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

void DFS(vector<vi> &Graph,vector<bool> &vis,int start_node,int color){
     vis[start_node] = true;
        for(auto element : Graph[start_node]){
            if(!vis[element])
               DFS(Graph,vis,element,color);
        }
}
void solve(){
    int n,m;cin>>n>>m;
    vector<int> Graph[n][m];
     for(int i=0;i<m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        u--,v--,c--;
        Graph[u][c].push_back(v);
        Graph[v][c].push_back(u);
     }
}
signed main(){
    int t = 1;
    // cin>>t;
    while(t--){
       solve();
    }
    return 0;
}




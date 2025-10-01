// Jai shree Ram
// Shivam verma

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <map>
#include <set>
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

// debug code

#ifndef ONLINE_JUDGE
#define shivam(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define shivam(x)
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


// Inbuilt Function

#define sum(a) (accumulate((a).begin(), (a).end(), 0LL))
#define unique_el(s) sort(all(s)) ; s.erase(unique(s.begin(), s.end()), s.end())
#define minel(a) (*min_element((a).begin(), (a).end()))
#define maxel(a) (*max_element((a).begin(), (a).end()))
#define mini(a) (min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a) (max_element((a).begin(), (a).end()) - (a).begin())
#define cnt(a, x) (count((a).begin(), (a).end(), (x)))
#define lob(a, x) (lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define upb(a, x) (upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

// Bit Manupulatoin operations 

#define bits(x) __builtin_popcount(x)
#define bitsll(x) __builtin_popcountll(x)
#define msb(x) (31 - __builtin_clz(x))
#define msbll(x) (63 - __builtin_clzll(x))
#define lsb(x) __builtin_ctz(x)
#define lsbll(x) __builtin_ctzll(x)

bool check_bit(int x ,int k){return x&(1<<k);}
int set_bit(int x,int k){return x|(1<<k);}
int Unset_bit(int x,int k){return x&(~(1<<k));}
int flip_bit(int x,int k){return x^(1<<k);}


template <class T> istream & operator>> (istream &in, vector<T> &v) {
    for (auto &vl : v) { in >> vl;} return in; }
template <typename T> void pvec(vector<T>&v) {
    for(auto i : v) {cout << i << " ";} cout << endl;}

// output array    

template <typename T>
ostream& operator<<(ostream &out, const vector<T>& v) {
    for (const auto &i : v) {
        out << i << " ";
    }
    return out;
}

int a[200010];
int dp[200010];

int Solve(int n){
    if(dp[n] != -1) return dp[n];
    int maxans = 1;
    for(int i = 0; i < n; i++){
        if(a[i] < a[n]) maxans = max(maxans, 1 + Solve(i));
    }
    dp[n] = maxans;
    return maxans;
}

void MahavirCoder(){
    int n; cin >> n;
    loop(i, n) cin >> a[i];
    memset(dp, -1, sizeof(dp));
    int ans = 1;
    Solve(n-1);
    for(int i = 0; i < n; i++){
        ans = max(ans, Solve(i));
    }
    cout << ans << endl;
}
int main(){
    int t = 1;
    // cin>>t;
    while(t--){
        MahavirCoder();
    }
}
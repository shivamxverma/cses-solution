// Jai shree Ram
// Shivam verma

#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

 
// some common Defination

const long long INF = LLONG_MAX;
#define ll long long int
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define vc vector<ll>
typedef pair<int,int> pi;
const int mod = 1000000007;
const int N = 1e5;
#define endl "\n" 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sloop(i,a,b) for (int i = a; i < b; i++)
#define loop(i,b) for (int i = 0; i < b; i++)
#define rloop(i,a,b) for (int i = a; i >= b; i--)
#define print(str) cout << str << "\n"

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


// Debug

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

bool cmp(pair<int,pair<int,int>> &a , pair<int,pair<int,int>> &b){
    if(a.first == b.first)return a.s.f < b.s.f;
    return a.f < b.f;
}

void MahavirCoder() {
    int n;cin>>n;
    vector<pair<int,pair<int,int>>> vp(n);
    loop(i,n){
        int x,y;cin>>x>>y;
        vp[i] = {x,{y,i}};  
    }

    sort(all(vp)); 

    int room = 0;

    int prev = vp[0].s.f;

    sloop(i,1,n){
        if(vp[i].f > prev){
            
        }
    }
    
    // shivam(vp);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    MahavirCoder();
    return 0;
}

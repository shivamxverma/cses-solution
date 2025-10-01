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

long long power(long long a, long long b)
{  
    long long res = 1;
    while (b > 0) {
        
        if (b & 1) {
            res = (res * a);
        }
        a = (a * a);
        b >>= 1;
    }
    return res;
}

void MahavirCoder() {
    ll n;
    cin >> n;
    vector<ll> tt(20,0);
    ll prev = 0;
    ll sum1to9 = 45;
    for(ll i = 1 ; power(10,i) <= n ; i++){
        ll cur = 10*prev + power(10,i-1)*sum1to9;
        tt[i] = cur;
        prev = tt[i];
    }
    ll dd = 1;
    while (dd * ((ll)pow(10, dd - 1)) * 9 < n) {
        n = n - dd * ((ll)pow(10, dd - 1)) * 9;
        dd++;
    }
    ll number = (ll)pow(10, dd - 1) + (n - 1) / dd;
    string numberStr = to_string(number);
    // cout << numberStr << endl;
    // cout << "-------------\n";
    int nod = numberStr.size() - 1;
    ll sum = 0;
    for(int i=0 ; i<=nod ; i++){
        int digit = numberStr[i] - '0' - 1;
        // cout << digit << endl;
        if(digit >= 0){
            if(i < nod){
                // cout << (digit+1) << " " << tt[nod-i] << " " << power(10,nod-i-1) << " " << (digit*(digit+1))/2 << endl;
                sum += (digit + 1)*tt[nod-i] + power(10,nod-i-1) * (digit*(digit+1))/2;
            } else {
                // cout << ((digit+1)*(digit+2))/2 << endl;
                sum += ((digit+1)*(digit+2))/2;
            }
        }
    }
    cout << sum << endl;
}

int main(){
    int t = 1;
    cin>>t;
    while(t--){
        MahavirCoder();
    }
}
// Jai shree Ram
// Shivam verma

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
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

// Inbuilt Function

#define sum(a) (accumulate((a).begin(), (a).end(), 0LL))
#define unique_el(s) \
    sort(all(s));    \
    s.erase(unique(s.begin(), s.end()), s.end())
#define minel(a) (*min_element((a).begin(), (a).end()))
#define maxel(a) (*max_element((a).begin(), (a).end()))
#define mini(a) (min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a) (max_element((a).begin(), (a).end()) - (a).begin())
#define cnt(a, x) (count((a).begin(), (a).end(), (x)))
#define lob(a, x) (lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define upb(a, x) (upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

// input array

template <class T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &vl : v)
    {
        in >> vl;
    }
    return in;
}
template <typename T>
void pvec(vector<T> &v)
{
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

// output array

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const auto &i : v)
    {
        out << i << " ";
    }
    return out;
}

// Prefix sum

template <typename T>
void prefixSum(const vector<T> &arr, vector<T> &prefix)
{
    int n = arr.size();
    prefix.resize(n);
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }
}

// ll solve(vc &a, int k, vc &dp) {

//     if (k == 0) return 1;
//     if (dp[k] != -1) return dp[k];

//     ll ans = 0;

//     for(auto e : a) {
//         if (e <= k) {
//             ans = (ans + solve(a,k-e,dp))%mod;
//         }
//     }

//     return dp[k] = ans;
// }


void MahavirCoder() {
    ll n, k;
    cin >> n >> k;
    vc v(n);
    cin >> v;
    vc dp(k + 1, 0);

    // cout << solve(v,k,dp) << endl;

    dp[0] = 1;

    sloop(i,1,k+1){
        sloop(j,0,n){
            if(v[j]<=i)dp[i] = (dp[i] + dp[i-v[j]])%mod;
        }
    }

    cout << dp[k] << endl;
    
}


int main()
{
    int t = 1;
    // cin>>t;
    while (t--)
    {
        MahavirCoder();
    }
}
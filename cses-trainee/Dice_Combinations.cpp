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

// Recursive Dp Code

// int solve(int n,vc &dp){
//     if(n == 0)return 1;
//     if(dp[n]!=-1)return dp[n];
//     ll ans = 0;
//     sloop(i,1,7){
//         if(n-i>=0)ans = (ans + solve(n-i,dp))%mod;
//     }
//     return dp[n] = ans;
// }

void MahavirCoder() {
    int n;cin>>n;
    vc dp(n+1,-1);
    
    dp[0] = 1;

    sloop(i,1,n+1){
        dp[i] = 0;
        sloop(j,1,7){
            if(i-j>=0)dp[i] = (dp[i] + dp[i-j])%mod;
        }
    }

    cout << dp[n] << endl;
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
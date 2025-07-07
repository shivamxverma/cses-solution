// Jai shree Ram
// Shivam verma

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <set>
#include <map>
using namespace std;

// some common Defination

const long long INF = LLONG_MAX;
#define ll long long int
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define vc vector<ll>
typedef pair<int, int> pi;
const int mod = 1000000007;
const int N = 1e6+5;
#define endl "\n"
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sloop(i, a, b) for (int i = a; i < b; i++)
#define loop(i, b) for (int i = 0; i < b; i++)
#define rloop(i, a, b) for (int i = a; i >= b; i--)
#define print(str) cout << str << "\n"

ll dp[N][2];

int main()
{

    dp[1][0] = 1;
    dp[1][1] = 1;

    for (int i = 2; i <= N; i++) {
        dp[i][1]=(2*(dp[i-1][1]%mod))%mod + (dp[i-1][0]%mod);
		dp[i][0]=(dp[i-1][1]%mod)+(4*(dp[i-1][0]%mod))%mod;
    }

    int t = 1;
    cin>>t;
    while (t--)
    {
        int n;cin>>n;
		cout<<(dp[n][0]%mod+dp[n][1]%mod)%mod<<"\n";
    }
}
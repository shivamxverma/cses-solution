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
const int N = 1e5;
#define endl "\n"
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define loop(i, a, b) for (int i = a; i < b; i++)
#define Loop(i, b) for (int i = 0; i < b; i++)
#define Rloop(i, a, b) for (int i = a; i >= b; i--)
#define print(str) cout << str << "\n"


void MahavirCoder()
{
    int n,m;cin>>n>>m;

    vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));

    for(int i = 1 ; i<=n ; i++){
        for(int j = 1 ; j<=m ; j++){
            if(i == j) {
                dp[i][j] = 0;
                continue;
            }
            ll mincut = INF;
            for(int k = 1 ; k < i ; k++){
                ll cut = 1 + dp[k][j] + dp[i-k][j];
                mincut = min(cut, mincut);
            }
            for(int k = 1 ; k < j ; k++){
                ll cut = 1 + dp[i][k] + dp[i][j-k];
                mincut = min(cut, mincut);
            }
            dp[i][j] = mincut;
        }
    }

    cout << dp[n][m] << endl;
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
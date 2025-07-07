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
    string s,t;cin>>s>>t;

    int n = s.size();
    int m = t.size();
    vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));

    for(int i = 0; i <= n; i++) dp[i][0] = i;
    for(int j = 0; j <= m; j++) dp[0][j] = j;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min({dp[i-1][j],   
                                    dp[i][j-1],   
                                    dp[i-1][j-1]}); 
            }
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
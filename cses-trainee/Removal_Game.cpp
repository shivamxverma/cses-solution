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

ll solve(int i,int j,int n,vc &a,vector<vector<ll>> &dp){

    if(i > j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(i == j){
        return a[i];
    }

    ll left = a[i]-solve(i+1,j,n,a,dp);
    ll right = a[j]-solve(i,j-1,n,a,dp);

    int mx = max(left,right);

    return dp[i][j] = mx;
}

void MahavirCoder()
{
    int n;cin>>n;
    vc a(n);
    for(int i=0 ; i<n ; i++)cin>>a[i];

    vector<vector<ll>> dp(n+1,vector<ll> (n+1,-1));

    ll total = accumulate(a.begin(),a.end(),0ll);
    ll diff = solve(0,n-1,n,a,dp);

    cout << (total+diff)/2 << endl;
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
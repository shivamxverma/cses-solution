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

int n;
int times[1001];
int skill[1001];

int dp[101][101][101];

int Solve(int n,int remtime,int remslot){
    if(n == 0){
        if(times[0] <= remtime && remslot > 0) return skill[0];
        return 0;
    }
    if(dp[n][remtime][remslot] != -1)return dp[n][remtime][remslot];
    int take = 0;
    if(times[n] <= remtime && remslot > 0){
        take = skill[n] + Solve(n-1,remtime-times[n],remslot-1);
    }
    int nottake = Solve(n-1,remtime,remslot);

    return dp[n][remtime][remslot] = max(take,nottake);
}

int main()
{
    cin>>n;
    int t,s;cin>>t>>s;
    for(int i=0 ; i<n ; i++)cin>>times[i]>>skill[i];
    memset(dp,-1,sizeof(dp));

    cout << Solve(n-1,t,s) << endl;
    return 0;
}

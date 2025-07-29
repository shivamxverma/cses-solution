// Jai shree Ram
// Shivam verma

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
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

bool cmp(vector<ll> &a,vector<ll> &b){
    if(a[0] == b[0])return a[1]<b[1];
    return a[0] < b[0];
}

void MahavirCoder()
{
    int n;cin>>n;
    vector<vector<ll>> projects;

    for(int i=0 ; i<n ; i++){
        ll s,e,val;
        cin>>s>>e>>val;
        projects.push_back({s,e,val});
    }

    sort(projects.begin(), projects.end(), [](const vector<ll>& a, const vector<ll>& b) {
        return a[1] < b[1];
    });

    vector<ll> dp(n, 0);

    vector<ll> ends(n);
    for (int i = 0; i < n; ++i) ends[i] = projects[i][1];

    for (int i = 0; i < n; ++i) {
        ll incl = projects[i][2];
        int l = lower_bound(ends.begin(), ends.end(), projects[i][0]) - ends.begin() - 1;
        if (l >= 0) incl += dp[l];
        dp[i] = max((i > 0 ? dp[i-1] : 0), incl);
    }

    cout << dp[n-1] << endl;
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
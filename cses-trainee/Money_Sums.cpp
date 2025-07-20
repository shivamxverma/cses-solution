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

vc ans;

map<pair<int, int>, bool> memo;

void solve(int i, vc &a, int cur) {
    if (i == a.size()) {
        if (cur > 0) ans.push_back(cur);
        return;
    }

    if (memo[{i, cur}]) return;
    memo[{i, cur}] = true;

    solve(i + 1, a, cur + a[i]);
    solve(i + 1, a, cur);
}

void MahavirCoder()
{
    int n; cin >> n;
    vc a(n);
    for(int i=0 ; i<n ; i++)cin>>a[i];

    sort(all(a));

    solve(0, a, 0);

    cout << ans.size() << endl;

    for (auto e : ans) cout << e << " ";
    cout << endl;
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
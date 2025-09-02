// Jai shree Ram
// Shivam verma

#include <bits/stdc++.h>
#include<iostream>
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

int Solve(int target,vector<int> &a,vector<pair<int,int>> &dp){
    if(target == 0)return 0;
    if(dp[target].first != -1)return dp[target].first;
    int mini = INT_MAX;
    for(int i=0 ; i<a.size() ; i++){
        if(a[i] <= target){
            int res = Solve(target-a[i],a,dp);
            if(res != -1) {
                if(1 + res < mini) {
                    mini = 1 + res;
                    dp[target].second = i;
                }
            }
        }
    }
    return dp[target].first = (mini == INT_MAX ? -1 : mini);
}

void MahavirCoder() {
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++){
        cin>>a[i];
    }
    vector<pair<int,int>> dp(k+1,{-1,-1});
    cout << Solve(k,a,dp) << endl;

    for(int i = 0 ; i<k ; i++){
        cout << dp[i].first << " " << dp[i].second << endl;
    }
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
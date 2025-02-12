// Jai shree Ram
// Shivam verma

#include<bits/stdc++.h>
using namespace std;
 
// some common Defination

const long long INF = LLONG_MAX;
#define ll long long int
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define vc vector<ll>
typedef pair<int,int> pi;
const int mod = 1000000007;
const int N = 1e5;
#define endl "\n" 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define loop(i,a,b) for (int i = a; i < b; i++)
#define Loop(i,b) for (int i = 0; i < b; i++)
#define Rloop(i,a,b) for (int i = a; i >= b; i--)
#define print(str) cout << str << "\n"

// input array

template <class T> istream & operator>> (istream &in, vector<T> &v) {
    for (auto &vl : v) { in >> vl;} return in; }
template <typename T> void pvec(vector<T>&v) {
    for(auto i : v) {cout << i << " ";} cout << endl;}
 
int helper(int x,vector<int> &v,vector<int> &dp){
    if(x<0)return INT_MAX;
    if(x == 0)return 0;
    if(dp[x]!=-1)return dp[x];
    int minstep = INT_MAX;
    for(auto ele : v){
        int steps = helper(x-ele,v,dp);
        if(steps!=INT_MAX)minstep = min(minstep,1 + steps);
    }
    return dp[x] = minstep;
}

void shivamv_99(){
  int n,x;cin>>n>>x;
  vector<int> v(n);cin>>v;
  vector<int> dp(x+1,-1);
  int xd = helper(x,v,dp); 
  cout << (xd == INT_MAX?-1:xd) << endl;
}
int main(){
    int t = 1;
    // cin>>t;
    while(t--){
        shivamv_99();
    }
}
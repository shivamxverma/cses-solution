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


int solver(int n,vector<int> &dp){
    if(n==0)return 1;
    if(n<0)return 0;
    if(dp[n]!=-1)return dp[n];
    int ways = 0;
    for(int i=1 ; i<=6 ; i++){
        ways = (ways + solver(n-i,dp))%mod;
    }
    return dp[n] = ways;
}

void shivamv_99(){
  int n;cin>>n;
  vector<int> dp(n+1,-1);
  cout << solver(n,dp) << endl;
}
int main(){
    int t = 1;
    // cin>>t;
    while(t--){
        shivamv_99();
    }
}
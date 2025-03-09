// Jai shree Ram
// Shivam verma

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod = 1000000007;

void MahavirCoder(){
  int n,m;cin>>n>>m;
  vector<int> v(n);
  for(int i=0 ; i<n ; i++){
    cin>>v[i];
  }

  vector<vector<int>> dp(n+1,vector<int>(m+1,0));
  
  if(v[0]>0)dp[0][v[0]] = 1;
  else for(int i=1 ; i<=m ; i++)dp[0][i] = 1;

  for(int i=1 ; i<n ; i++){
    if(v[i]==0){
      for(int d = 1 ; d<=m ; d++){
        if(d-1>=1)dp[i][d] = (dp[i][d] + dp[i-1][d-1])%mod;
        dp[i][d] = (dp[i][d] + dp[i-1][d])%mod;
        if(d+1<=m)dp[i][d] = (dp[i][d] + dp[i-1][d+1])%mod;
      }
    } else {
      if(v[i]-1>=1)dp[i][v[i]] = (dp[i][v[i]] + dp[i-1][v[i]-1])%mod;
      dp[i][v[i]] = (dp[i][v[i]] + dp[i-1][v[i]])%mod;
      if(v[i]+1<=m)dp[i][v[i]] = (dp[i][v[i]] + dp[i-1][v[i]+1])%mod;
    }
  }

  ll ans = 0;
  for(int j = 1; j<=m; ++j){
    (ans += dp[n - 1][j]) %= mod;
  }
 
  cout<<ans<<endl;

  
}

int main(){
    int t = 1;
    while(t--){
        MahavirCoder();
    }
}
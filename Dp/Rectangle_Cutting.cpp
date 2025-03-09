// Jai shree Ram
// Shivam verma

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod = 1000000007;

void MahavirCoder(){
  int n,m;cin>>n>>m;
  vector<vector<ll>> dp(n+2,vector<ll>(m+2,1e9));

  for(int i=1 ; i<=n ; i++){
    for(int j=1 ; j<=m ; j++){
      
      if(i==j){
        dp[i][j] = 0;
        continue;
      }

      for(int h=1 ; h<=i ; h++){
        dp[i][j] = min(dp[i][j],dp[h][j]+dp[i-h][j] + 1);
      }

      for(int v=1 ; v<=j ; v++){
        dp[i][j] = min(dp[i][j],dp[i][v]+dp[i][j-v] + 1);
      }
    }
  }
  cout << dp[n][m] << endl;
}

int main(){
    int t = 1;
    while(t--){
        MahavirCoder();
    }
}
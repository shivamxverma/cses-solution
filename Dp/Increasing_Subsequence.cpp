// Jai shree Ram
// Shivam verma

#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<int> &v,int prev,vector<int> &dp){
    if(n==0){
      return (prev>=v[0]);
    }
    if(dp[n]!=-1)return dp[n];
    int take = 0,nottake = 0;
    if(prev>=v[n])take = 1 + solve(n-1,v,v[n],dp);
    nottake = solve(n-1,v,prev,dp);

    return dp[n] = max(take , nottake);
}

void MahavirCoder(){
  int n;cin>>n;
  vector<int> v(n);
  for(int i=0 ; i<n ; i++){
    cin>>v[i];
  }
  vector<int> dp(n+1,-1);

  cout <<  solve(n-1,v,INT_MAX,dp) << endl;

  cout << dp[n-1] << endl;

  for(auto x : dp)cout << x <<  " ";
  cout << endl;
}

int main(){
    int t = 1;
    while(t--){
        MahavirCoder();
    }
}
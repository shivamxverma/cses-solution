// Jai shree Ram
// Shivam verma

#include<bits/stdc++.h>
using namespace std;

int solve(int n,int xx,vector<int> &v,int m,vector<vector<int>> &dp){
   if(n==0){
    if(v[0]!=0){
      if(abs(v[0]-xx)<=1)return 1;
      return 0;
    } else {
      if(xx == 1){
        if(m>xx)return 2;
        else return 1;
      }
      else {
        if(m>xx)return 3;
        else return 2;
      }
    }
   }
   if(dp[n][xx]!=-1)return dp[n][xx];
   int ans = 0;
   if(v[n]==0){
    for(int i=1 ; i<=m ; i++){
       if(abs(xx-i)<=1 || xx == 100001){
        ans += solve(n-1,i,v,m,dp);
       }
    }
   } else{
    ans += solve(n-1,v[n],v,m,dp);
   }
   return dp[n][xx] = ans;
} 

void MahavirCoder(){
  int n,m;cin>>n>>m;
  vector<int> v(n);
  for(int i=0 ; i<n ; i++){
    cin>>v[i];
  }
  int xx = 100001;
  vector<vector<int>> dp(n+1,vector<int>(xx+1,-1));
  cout << solve(n-1,xx,v,m,dp) << endl;
}

int main(){
    int t = 1;
    while(t--){
        MahavirCoder();
    }
}
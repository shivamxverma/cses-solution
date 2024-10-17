#include<bits/stdc++.h>
using namespace std;

set<string> ans;
void solver(string s,char prev,string temp){
  if(i == n){
    ans.insert(temp);
  }
  for(auto c : s){
      temp += c;
      if(c!=prev){
        solver(s,c,)
      }
  }
}

void solve(){
    string s;cin>>s;
    int n = s.length();
    
}
signed main(){
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
}
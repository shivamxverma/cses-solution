#include<bits/stdc++.h>
using namespace std;
 
void solve(){
     string s;cin>>s;
     int n = s.length();
     int mx = 0;
     for(int i=0 ; i<n ; i++){
         int j = i;
         while(j < n && s[i] == s[j]){
          j++;
         }
         mx = max(mx,j-i);
         i = j-1;
     }
     cout << mx << endl;
}
signed main(){
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
}
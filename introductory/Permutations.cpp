#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    if(n==3 || n==2){
      cout << "NO SOLUTION";
      return;
    }
    vector<int> ans;
    for(int i = 2 ; i<=n ; i+=2)ans.push_back(i);
    for(int i = 1 ; i<=n ; i+=2)ans.push_back(i);

    for(auto x : ans)cout << x << " ";
}
signed main(){
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
}
#include<bits/stdc++.h>
using namespace std;
 
void solve(){
    int x,y;cin>>x>>y;
    long long int base = max(x,y);
    base = base*(1ll)*base - base + 1;
    if(base&1){
      if(x<y)base += (y-x);
      else base -= (y-x);
    }
    else{
      if(x<y)base -= (y-x);
      else base += (y-x);
    }
    cout << base << endl;
}
signed main(){
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
}
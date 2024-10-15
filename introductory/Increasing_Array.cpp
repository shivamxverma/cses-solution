#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve(){
    int n;cin>>n;
    vector<int> v(n);
    ll x;cin>>x;
    ll ele = x;
    ll cost = 0;
    for(int i=0 ; i<n-1 ; i++){
      ll x;cin>>x;
      if(x>ele)ele = x;
      else cost += ele - x;
    }
    cout << cost << endl;
}
signed main(){
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
}
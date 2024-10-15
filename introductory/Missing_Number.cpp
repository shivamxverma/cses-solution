#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> a(n-1);
    long long int sum = 0;
    for(int i=0;i<n-1;i++){
        cin>>a[i];
        sum += a[i];
    }
    cout << n*(1ll)*(n+1)/2 - sum << endl;
}
signed main(){
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
}

// Time Complexity: O(N)
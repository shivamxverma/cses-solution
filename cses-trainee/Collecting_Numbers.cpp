// Jai shree Ram

#include<bits/stdc++.h>
using namespace std;

void MahavirCoder(){
    int n; cin >> n;
    vector<long long> a(n);
    for(int i=0;  i<n ; i++){
        cin>>a[i];
    }
    int ans = 0;
    int prev = INT_MAX;

    for(int i=0 ; i<n ; i++){
        if(prev>a[i]){
            ans++;
            prev = a[i];
        }
    }

    cout << ans << endl;
}

int main(){
    int t = 1;
    // cin>>t;
    while(t--){
        MahavirCoder();
    }
}
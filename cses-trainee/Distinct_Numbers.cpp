// Jai shree Ram

#include<bits/stdc++.h>
using namespace std;

void MahavirCoder(){
    int n,ans = 0;cin>>n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++)cin>>a[i];
    sort(a.begin(),a.end());

    for(int i=0 ; i<n ; i++){
        int j = i;
        while(j<n && a[i]==a[j])j++;
        ans++;
        i = j-1;
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
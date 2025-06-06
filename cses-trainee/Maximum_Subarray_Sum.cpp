// Jai shree Ram

#include<bits/stdc++.h>
using namespace std;

void MahavirCoder(){
    int n; cin >> n;
    vector<long long> a(n);
    for(int i=0;  i<n ; i++){
        cin>>a[i];
    }

    long long b = a[0],mx = a[0];

    for(int i=1 ; i<n ; i++){
        b = max(a[i],b+a[i]);
        mx = max(mx,b);
    }

    cout << mx << endl;
}

int main(){
    int t = 1;
    // cin>>t;
    while(t--){
        MahavirCoder();
    }
}
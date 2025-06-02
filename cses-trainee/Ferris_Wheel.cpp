// Jai shree Ram

#include<bits/stdc++.h>
using namespace std;

void MahavirCoder(){
    int n,k,ans = 0;
    cin >> n >> k;
    vector<long long> a(n);
    for(int i=0 ; i<n ; i++)cin >>a[i];

    sort(a.begin(),a.end());

    int l = 0 , r = n-1;

    while(l<=r){
        long long sum = a[l]+a[r];

        if(sum<=k){
            ans++;
            l++;
            r--;
        }
        else {
            ans++;
            r--;
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
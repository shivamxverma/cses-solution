// Jai shree Ram

#include<bits/stdc++.h>
using namespace std;

void MahavirCoder(){
    int n;cin>>n;
    vector<long long> a(n);
    for(int i=0;  i<n ; i++){
        cin>>a[i];
    }

    long long ans = LLONG_MAX;

    sort(a.begin(),a.end());

    // for(auto it : a)cout << it << " ";
    // cout << endl;

    if(n%2==0){
        int mid = a[n/2];
        long long xx = 0;

        for(int i=0 ; i<n ; i++){
            xx += abs(a[i]-mid);
        }

        mid = a[(n/2)+1];

        ans = min(ans,xx);

        xx = 0;

        for(int i=0 ; i<n ; i++){
            xx += abs(a[i]-mid);
        }

        ans = min(ans,xx);
    } else {
        int mid = a[n/2];
        long long xx = 0;
        // cout << mid << endl;

        for(int i=0 ; i<n ; i++){
            xx += abs(a[i]-mid);

            // cout << mid << " " << a[i] << endl;
        }

        ans = min(ans,xx);
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
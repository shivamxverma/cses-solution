// Jai shree Ram

#include<bits/stdc++.h>
using namespace std;

void MahavirCoder(){
    int n,m,k;
    vector<long long> app, apar;
    cin >> n >> m >> k;
    app.resize(n);
    apar.resize(m);
    for(int i=0 ; i<n ; i++)cin >>app[i];
    for(int i=0 ; i<m ; i++)cin >>apar[i];


    sort(app.begin(),app.end());
    sort(apar.begin(),apar.end());

    int l = 0, r = 0,ans = 0;

    while(l<n && r<m){
        long long left = app[l]-k;
        long long right = app[l]+k;
        if(left <= apar[r] && apar[r] <= right){
            l++;
            r++;
            ans++;
        } else if(left > apar[r]){
            r++;
        } else if(right < apar[r]){
            l++;
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
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int m = 1e9+7;

ll expo(ll a,ll b){
    a%=m;
    ll res = 1;
    while(b>0){
        if(b&1)res = res * a % m;
        a = a*a%m;
        b>>=1;
    }
    return res;
}

void MahavirCoder(){
    ll a,b,c;cin>>a>>b>>c;
    ll d = expo(b,c);
    ll ans = expo(a,d);
    cout << ans << endl;
}

int main(){
    int t;cin>>t;
    while(t--){
        MahavirCoder();
    }
}
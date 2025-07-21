#include<iostream>
#include<bits/stdc++.h>
#include<set>
using namespace std;

#define ll long long
const int m = 1e9+7;


void MahavirCoder(){
    int n;cin>>n;

    if( n == 1){
        cout << 1 << endl;
        return;
    }
    
    int ans = 1;

    for(int i=2 ; i<=sqrt(n) ; i++){
        if(n%i == 0){
            ans++;
            if(i != (n/i))ans++;
        }
    }
    cout << ans+1 << endl;
}

int main(){
    int t;cin>>t;
    while(t--){
        MahavirCoder();
    }
}
#include<iostream>
#include<bits/stdc++.h>
#include<set>
#include<map>
using namespace std;

#define ll long long
const int m = 1e9+7;


void MahavirCoder(){
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++)cin>>a[i];

    sort(a.begin(),a.end());

    unordered_map<int,int> track;
    track[1] = 1;

    int ans = 1;

    for(auto ele : a){
        for(int i=1 ; i*i<=ele ; i++){
            if(ele%i == 0){
                ans = max(ans,i);
                ans = max(ans,ele/i);
                // track[i]++;
                // track[(ele/i)]++;
            }
        }
    }

    cout << ans << endl;
}

int main(){
    int t = 1;
    while(t--){
        MahavirCoder();
    }
}
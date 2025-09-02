// Jai shree Ram

#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<iostream>
#include<map>
#include<set>
using namespace std;

void MahavirCoder(){
    int a,b;cin>>a>>b;
    if(a<b)swap(a,b);

    int ta;

    if(a%2==0)ta = a/2;
    else ta = a/2 + 2;

    if(b < ta)cout << "NO\n";
    else if((b-ta)%3==0)cout << "YES\n";
    else cout << "NO\n";
}
int main(){
    int t = 1;
    cin>>t;
    while(t--){
        MahavirCoder();
    }
}
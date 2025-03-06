#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const int N = 200000;

void build(){
   
}

void update(){

}

void query(){

}

void solve(){
    int n,q;cin>>n>>q;
    vector<ll> pre = {0};
    for(int i=0 ; i<n ; i++){
      ll x;cin>>x;
      pre.push_back(pre.back()+x);
    }

    while(q--){
      int l,r;cin>>l>>r;
      l--;
      cout << pre[r]-pre[l] << endl;
    }
}

int main(){
  solve();
  return 0;
}
#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b){
  return a.second < b.second;
}


int main(){
    int n;cin>>n;
    vector<pair<int,int>> a(n);
    for(int i=0 ; i<n ; i++){
      cin>> a[i].first;
      cin>> a[i].second;
    }
    

    sort(a.begin(),a.end(),cmp);
    
    int prev = 0;
    int ans = 0;
    for(auto [x,y] : a){
      if(prev<=x){
        ans++;
        prev = y;
      }
    }
    cout << ans << endl;
}
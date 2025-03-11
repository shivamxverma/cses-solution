#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool cmp(pair<int,int> a,pair<int,int> b){
  if(a.first == b.first)return a.second<b.second;
  return a.first < b.first;
}

signed main(){
    int n;cin>>n;
    vector<pair<int,int>> a(n);
    for(int i=0 ; i<n ; i++){
      cin>> a[i].first;
      cin>> a[i].second;
    }
    sort(a.begin(),a.end(),cmp);
    int ans = 1,curr = 1,minprev = INT_MAX;
    for(int i=0 ; i<n-1 ; i++){
      auto [xx, yy] = a[i];
      minprev = min(minprev,yy);
      int j = i;
      if(minprev>a[i+1].first){
         curr++;
      } else {
        curr = 1;
        minprev = yy;
      }
       
      ans = max(ans,curr);
    }
    cout << ans << endl;
}
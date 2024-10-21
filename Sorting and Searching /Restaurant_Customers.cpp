#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b){
  return a.first < b.first;
}

int main(){
    int n;cin>>n;
    vector<pair<int,int>> a(n);
    for(int i=0 ; i<n ; i++){
      cin>> a[i].first;
      cin>> a[i].second;
    }
    sort(a.begin(),a.end(),cmp);
    int ans = 1;
    for(int i=0 ; i<n ; i++){
      int x = a[i].first,y = a[i].second;
      auto it = upper_bound(a.begin(), a.end(), make_pair(y, INT_MAX), cmp);
      it--;
      int ind = (it == a.end())?n-1:it - a.begin();
      ans = max(ans,(n-ind));
      cout << x << " " << y << "      ";
      cout << it->first << " " <<it->second << "   " << ind - i + 1 << endl;
    }
    cout << ans << endl;
}
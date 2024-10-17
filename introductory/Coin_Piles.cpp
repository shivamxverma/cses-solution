#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
      int x,y;cin>>x>>y;
      int n1x = x%2,n2x = x/2,n1y = y%2,n2y = y/2;
      if(n1x+n2x == n1y+n2y){
        if(x == y){
          if((x+y)%3==0)cout << "YES\n";
          else cout << "NO\n";
        }
        else cout << "YES\n";
      }
      else cout << "NO\n";
    }
}
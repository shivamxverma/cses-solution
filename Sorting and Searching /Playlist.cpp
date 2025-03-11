// Jai shree Ram
// Shivam verma

#include<bits/stdc++.h>
using namespace std;


const long long INF = LLONG_MAX;
#define ll long long int

void MahavirCoder() {
    int n;cin>>n;

    vector<int> a(n);

    for(int i=0 ; i<n; i++){
       cin>>a[i];
    }

    set<int> free;
    int ans = 1;

    for(int i=0 ; i<n ; i++){
      int j = i;
      while(j<n && free.find(a[j])==free.end()){
        free.insert(a[j]);
        j++;
      }

      ans = max(ans,j-i);
      
      i = j-1;

    }
    cout << ans << endl;
 }

int main(){
    int t = 1;
    while(t--){
        MahavirCoder();
    }
}

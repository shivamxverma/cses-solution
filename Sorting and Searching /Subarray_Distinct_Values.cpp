// Jai shree Ram
// Shivam verma

#include<bits/stdc++.h>
using namespace std;


void MahavirCoder() {
    int n,k,ans = 0,prev = 0;cin>>n>>k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
    map<int,int> free;
    int l = 0 , r = 0;
    while(r<n){
        while(r<n && free.size()<=k){
          if(free.size()==k && free[v[r]]==0)continue;
          free[v[r]]++;
          r++;
          ans++;
        }
        while(l<=r && free.size() == k){
          free[l]--;
          l++;
          ans++;
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
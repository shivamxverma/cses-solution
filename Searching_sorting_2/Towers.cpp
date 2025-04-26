// Jai shree Ram
// Shivam verma

#include<bits/stdc++.h>
using namespace std;

void MahavirCoder() {
    int n;cin>>n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
    set<int> free;
    free.insert(v[0]);
    int ans = 1;
    
    for(int i=1 ; i<n ; i++){
        auto it = free.upper_bound(v[i]);
        if(it == free.end()){
            ans++;
        }
        free.insert(v[i]);
    }
    cout << ans << endl;
}

int main(){
    int t = 1;
    while(t--){
        MahavirCoder();
    }
}
// Jai shree Ram
// Shivam verma

#include<bits/stdc++.h>
using namespace std;

void MahavirCoder() {
    int n,k;cin>>n>>k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
    map<int,int> free;
    set<int> st;
    int ans = 0;
    for(int i=0 ; i<n ; i++){
        if(st.size()<=k){
            
        }
        else {
            int xx = free[st.size()-k] + 1;
            ans += (i+1-xx+1);
        }
        st.insert(v[i]);
        if(free[st.size()]==0)free[st.size()] = i+1;
    }
    cout << ans << endl;
}

int main(){
    int t = 1;
    while(t--){
        MahavirCoder();
    }
}
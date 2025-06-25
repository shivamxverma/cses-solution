// Jai shree Ram

#include<bits/stdc++.h>
using namespace std;

void MahavirCoder(){
    int n; cin >> n;
    vector<long long> a(n);
    for(int i=0;  i<n ; i++){
        cin>>a[i];
    }

    map<int,int> memory;
    int prev = 0;
    int ans = 0;
    
    
    for(int i=0 ; i<n ; i++){
        if(memory[a[i]]>0){
            prev = max(prev,memory[a[i]]);
        }
        ans = max(ans,i+1-prev);
        memory[a[i]] = i+1;
    }
    
    cout << ans << endl;
}

int main(){
    int t = 1;
    // cin>>t;
    while(t--){
        MahavirCoder();
    }
}
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
    int ans = 0;
    int cur = 0;
    int prev = 0;
    
    for(int i=0 ; i<n ; i++){
        if(memory.find(a[i])==memory.end()){
            cur++;
        } else {
            if(prev>memory[a[i]]){
                cur++;
            }
            else {
                cur = i-memory[a[i]];
                prev = i;
            }
        }
        memory[a[i]] = i;
        ans = max(ans,cur);
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
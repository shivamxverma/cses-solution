// Jai shree Ram
// Shivam verma

#include<bits/stdc++.h>
using namespace std;

void MahavirCoder(){
    string s;cin>>s;
    int n = s.size();
    int ans = 0;
    for(int i = 0 ; i<s.size() ; i++){
        int j = i;
        while(j<n && s[i]==s[j])j++;
        ans = max(ans,j-i);
        i = j-1;
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
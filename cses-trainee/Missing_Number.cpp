// Jai shree Ram
// Shivam verma

#include<bits/stdc++.h>
using namespace std;

void MahavirCoder(){
    int n;cin>>n;
    long long sum = (n*(1ll)*(n+1))/2;

    // cout << sum << endl;

    for(int i=0 ; i<n-1 ; i++){
        int x;cin>>x;
        sum -= x;
        // cout << sum << endl;
    }

    cout << sum << endl;
}
int main(){
    int t = 1;
    // cin>>t;
    while(t--){
        MahavirCoder();
    }
}
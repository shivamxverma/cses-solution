// Jai shree Ram
// Shivam verma

#include<bits/stdc++.h>
using namespace std;

void MahavirCoder(){
    long long int n;cin>>n;

    while(n!=1){
        cout << n << " ";
        if(n&1)n = 3*n+1;
        else n/=2;
    }
    cout << 1 << endl;
}
int main(){
    int t = 1;
    // cin>>t;
    while(t--){
        MahavirCoder();
    }
}
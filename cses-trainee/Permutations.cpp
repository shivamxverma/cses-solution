// Jai shree Ram
// Shivam verma

#include<bits/stdc++.h>
using namespace std;

void MahavirCoder(){
    int n;cin>>n;
    int ans[n];

    if(n==1) {
        cout << 1 << endl;
        return ;
    } 

    if(n==2 || n==3){
        cout << "NO SOLUTION\n";
        return ;
    }

    if(n==4){
        cout << "2 4 1 3\n";
        return ;
    }

    int i = 0;
    int d = n&1 ? n-1 : n;

    while(d>0){
        ans[i++]=d;
        d-=2;
    }

    d = n&1 ? n : n-1;

    while(d>0){
        ans[i++]=d;
        d-=2;
    }

    for(auto i : ans)cout << i << " ";
    cout << endl;
}
int main(){
    int t = 1;
    // cin>>t;
    while(t--){
        MahavirCoder();
    }
}
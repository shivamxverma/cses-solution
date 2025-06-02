// Jai shree Ram
// Shivam verma

#include<bits/stdc++.h>
using namespace std;

void MahavirCoder(){
    int n;cin>>n;
    int a[n];
    for(int i=0 ; i<n ; i++)cin>>a[i];

    long long int ans = 0;
    int prev = a[0];

    for(int i=1 ; i<n ; i++){
        prev = max(prev,a[i-1]);
        int xx = prev-a[i];
        ans += (xx > 0 ? xx : 0);
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
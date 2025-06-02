// Jai shree Ram
// Shivam verma

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<long long> ans = {0,6,28};
    for(int i=4 ; i<=n ; i++){
        long long aa = (10+(i-4)*4)*(1ll)*(i-2) + 4 + (i-4)*2;
        long long sqared = i*i;
        long long tot = (sqared*(1ll)*(sqared-1))/2;
        ans.push_back(tot-aa);
    }


    for(int i=1 ; i<=n ; i++){
        cout << ans[i-1] << endl;
    }

}
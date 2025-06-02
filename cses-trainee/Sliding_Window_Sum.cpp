// Jai shree Ram
// Shivam verma

#include<bits/stdc++.h>
using namespace std;

void MahavirCoder(){
    int n,k;cin>>n>>k;
    int x,a,b,c;cin>>x>>a>>b>>c;

    long long mini = x;
    
    multiset<long long> free;
    vector<long long> tm = {x};
    
    for(int i=1 ; i<k ; i++){
        long long xi = (a*(1ll)*x+b)%c;
        mini = min(mini,xi);
        free.insert(xi);
        x = xi;
        tm.push_back(xi);
    }

    // cout << mini << endl;
    
    long long ans = mini;

    for(int i=k ; i<n ; i++){
        long long xi = (a*(1ll)*x + b)%c;
        mini = min(mini,xi);
        auto it = free.find(tm[i-k]);
        if (it != free.end()) {
            free.erase(it);
        }
        if (mini == tm[i-k]) {
            auto it = free.find(tm[i-k]);
            if (it == free.end()) {
                // free.erase(it);
                mini = *free.begin();
            }
            // mini = free.empty() ? mini : *free.begin();
        }

        // cout << mini << endl;

        ans ^= mini;
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
// Jai shree Ram
// Shivam verma

#include<bits/stdc++.h>
using namespace std;


const long long INF = LLONG_MAX;
#define ll long long int

void MahavirCoder() {
    int n,x;cin>>n>>x;

    vector<int> a(n);

    for(int i=0 ; i<n; i++){
       cin>>a[i];
    }

    map<int, pair<int, int>> free;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int upx = x - a[i] - a[j];
            if (free.find(upx) != free.end()) {
                cout << free[upx].first + 1 << " " << free[upx].second + 1 << " " << i + 1 << endl;
                return;
            }
        }
        for (int j = 0; j < i; j++) {
            free[a[i] + a[j]] = {j, i};
        }
    }

    cout << "NO\n";
    
 }

int main(){
    int t = 1;
    while(t--){
        MahavirCoder();
    }
}

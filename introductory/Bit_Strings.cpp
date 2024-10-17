#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
 
ll powerOfTwo(ll n) {
    ll result = 1;
    ll base = 2;
    while (n > 0) {
        if (n % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        n /= 2;
    }
    return result;
}

void solve(){
    int n;cin>>n;
    cout << powerOfTwo(n) << endl;
}
int main(){
    solve();
}
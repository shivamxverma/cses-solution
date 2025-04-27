
#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 1;
const int MOD = 1e9 + 7;

vector<long long> fact(N), invFact(N);

long long modPow(long long x, long long y, int mod) {
    long long res = 1;
    while (y) {
        if (y & 1) res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    invFact[N - 1] = modPow(fact[N - 1], MOD - 2, MOD);
    for (int i = N - 2; i >= 0; --i) {
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();
    
    long long n;cin>>n;

    if(n%2==1){
        cout << 0 << endl;
        return 0;
    }

    long long t = n-2;

    long long nn = (t)/2;

    long long ans = 1;

    for(long long i=2 ; i<=nn ; i+=2){
        long long xd = t-i*2;
        xd = xd/2;
        xd = (1<<xd);
        long long xx = nCr(nn,i);
        xx = (xx * (1ll) *xd)%MOD;
        ans = (ans + xx)*MOD;
    }

    long long xxd = t/2;
    xxd = 1<<xxd;

    ans = (ans + xxd)%MOD;

    cout << ans << endl;
}
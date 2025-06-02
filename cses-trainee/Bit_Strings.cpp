#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

long long binExp(long long a, long long b, long long mod) {
    long long res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    int n;cin>>n;
    cout << binExp(2, n, MOD) << endl;
    return 0;
}

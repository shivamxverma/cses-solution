#include <iostream>
#include <vector>
using namespace std;

#define ll long long
const int m = 1e9 + 7;

ll expo(ll a, ll b) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a) {
    return expo(a, m - 2);
}

void MahavirCoder() {
    int n;
    cin >> n;

    ll nod = 1;
    ll sod = 1;
    ll baseNum = 1;

    vector<pair<ll, ll>> div;

    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        div.push_back({x, y});

        nod = nod * (y + 1) % m;

        ll num = (expo(x, y + 1) - 1 + m) % m;
        ll den = modinv(x - 1);
        sod = sod * (num * den % m) % m;

        baseNum = baseNum * expo(x, y) % m;
    }

    ll exp = nod;
    if (exp % 2 == 0) exp /= 2;
    else exp = (exp + m) / 2;

    ll pod = expo(baseNum, exp);

    cout << nod << " " << sod << " " << pod << endl;
}

int main() {
    int t = 1;
    while (t--) {
        MahavirCoder();
    }
}

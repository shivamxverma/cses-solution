#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

bool possible(const vector<ll>& v, ll m, ll k) {
    ll total = 0;
    for (ll x : v) {
        total += m / x;
        if (total >= k) return true;
    }
    return total >= k;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    
    vector<ll> v(n);
    ll max_time = 0;
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
        max_time = max(max_time, v[i]);
    }

    ll l = 1, r = k * max_time;
    ll res = r;

    while (l <= r) {
        ll m = l + (r - l) / 2;
        if (possible(v, m, k)) {
            res = min(res, m); 
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
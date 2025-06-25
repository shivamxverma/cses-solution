// Jai shree Ram
// Shivam Verma

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void MahavirCoder() {
    int n, k; cin >> n >> k;
    ll x, a, b, c; cin >> x >> a >> b >> c;

    deque<pair<ll, int>> dq;
    ll xi = x;
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        if (i != 0) xi = (a * xi + b) % c;

        while (!dq.empty() && dq.back().first >= xi) {
            dq.pop_back();
        }

        dq.push_back({xi, i});

        if (!dq.empty() && dq.front().second <= i - k) {
            dq.pop_front();
        }

        if (i >= k - 1) {
            ans ^= dq.front().first;
        }
    }


    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    MahavirCoder();
    return 0;
}

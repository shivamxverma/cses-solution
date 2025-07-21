#include <bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long int

const int N = 2e5+5;
vector<ll> lazy(4*N);
vector<ll> seg(4*N);
vector<ll> a(N);
int n, q;

void build(int s, int e, int i = 1) {
    if (s == e) {
        seg[i] = a[s];
        return;
    }
    int m = (s + e) / 2;
    build(s, m, 2 * i);
    build(m + 1, e, 2 * i + 1);
    seg[i] = seg[2 * i] + seg[2 * i + 1];
}

void update(int pos, ll val, int s, int e, int i = 1) {
    if (s == e) {
        seg[i] = val;
        return;
    }
    int m = (s + e) / 2;
    if (pos <= m) update(pos, val, s, m, 2 * i);
    else update(pos, val, m + 1, e, 2 * i + 1);
    seg[i] = seg[2 * i] + seg[2 * i + 1];
}

ll Query(int l, int r, int s, int e, int i = 1) {
    if (r < s || l > e) return 0;
    if (l <= s && e <= r) return seg[i];
    int m = (s + e) / 2;
    ll left = Query(l, r, s, m, 2 * i);
    ll right = Query(l, r, m + 1, e, 2 * i + 1);
    return left + right;
}

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];

    build(0, n - 1);

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int k;
            ll val;
            cin >> k >> val;
            update(k - 1, val, 0, n - 1);
        } else {
            int l, r;
            cin >> l >> r;
            cout << Query(l - 1, r - 1, 0, n - 1) << endl;
        }
    }
}

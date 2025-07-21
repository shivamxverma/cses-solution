#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long int

const int N = 2e5+5;
int n, q;
vector<ll> seg(4*N);
vector<ll> lazy(4*N);

void build(int s, int e, int i, vector<ll> &a) {
    if (s == e) {
        seg[i] = a[s];
        return;
    }
    int m = (s + e) / 2;
    build(s, m, 2*i, a);
    build(m+1, e, 2*i+1, a);
}

void push(int s, int e, int i) {
    if (lazy[i] != 0) {
        seg[i] += lazy[i];
        if (s != e) {
            lazy[2*i] += lazy[i];
            lazy[2*i+1] += lazy[i];
        }
        lazy[i] = 0;
    }
}

void update(int s, int e, int i, int l, int r, ll val) {
    push(s, e, i);
    if (r < s || e < l) return;
    if (l <= s && e <= r) {
        lazy[i] += val;
        push(s, e, i);
        return;
    }
    int m = (s + e) / 2;
    update(s, m, 2*i, l, r, val);
    update(m+1, e, 2*i+1, l, r, val);
}

ll query(int s, int e, int i, int idx) {
    push(s, e, i);
    if (s == e) return seg[i];
    int m = (s + e) / 2;
    if (idx <= m) return query(s, m, 2*i, idx);
    else return query(m+1, e, 2*i+1, idx);
}

int main() {
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    build(0, n-1, 1, a);

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            ll val;
            cin >> l >> r >> val;
            l--, r--;
            update(0, n-1, 1, l, r, val);
        } else {
            int k;
            cin >> k;
            k--;
            cout << query(0, n-1, 1, k) << '\n';
        }
    }
}

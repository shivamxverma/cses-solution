#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const int N = 200007;
vector<ll> segTree(4*N+7, 0);

void build(int s, int e, int i) {
    if(s == e) {
        segTree[i] = 0;
        return;
    }
    int m = s + (e-s)/2;
    build(s, m, 2*i);
    build(m+1, e, 2*i+1);
    segTree[i] = segTree[2*i] + segTree[2*i+1];
}

void update(int s, int e, int i, int pos, ll val) {
    if(s == e) {
        segTree[i] += val;
        return;
    }
    int m = s + (e-s)/2;
    if(pos <= m) update(s, m, 2*i, pos, val);
    else update(m+1, e, 2*i+1, pos, val);
    segTree[i] = segTree[2*i] + segTree[2*i+1];
}

ll query(int s, int e, int l, int r, int i) {
    if(l > e || r < s) return 0;
    if(l <= s && e <= r) return segTree[i];
    int m = s + (e-s)/2;
    return query(s, m, l, r, 2*i) + query(m+1, e, l, r, 2*i+1);
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(0, n-1, 1);
    while(q--) {
        int op;
        cin >> op;
        if(op == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l--, r--;
            update(0, n-1, 1, l, x);
            if(r+1 < n) update(0, n-1, 1, r+1, -x);
        } else {
            int k;
            cin >> k;
            k--;
            ll diff_sum = query(0, n-1, 0, k, 1);
            cout << a[k] + diff_sum << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
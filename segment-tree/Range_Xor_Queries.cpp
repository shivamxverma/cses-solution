#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const int N = 200007;
vector<int> segTree(4*N+7, -1);

void build(int s, int e, int i, vector<int> &a) {
    if(s == e) {
        segTree[i] = a[s];
        return;
    }
    int left = 2*i, right = 2*i+1;
    int m = s + (e-s)/2;
    build(s, m, left, a);
    build(m+1, e, right, a);
    segTree[i] = segTree[left] ^ segTree[right];
}

int query(int s, int e, int l, int r, int i) {
    if(l > e || r < s) return 0;
    if(l <= s && e <= r) return segTree[i];
    int m = s + (e-s)/2; 
    return query(s, m, l, r, 2*i) ^ query(m+1, e, l, r, 2*i+1);
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(0, n-1, 1, a);
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << query(0, n-1, l-1, r-1,1) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    solve();
    return 0;
}
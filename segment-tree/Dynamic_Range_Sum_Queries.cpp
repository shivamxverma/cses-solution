#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const int N = 200007;
vector<ll> segTree(4*N+7, -1);

void build(int s, int e, int i, vector<ll> &a) {
    if(s == e) {
        segTree[i] = a[s];
        return;
    }
    int left = 2*i, right = 2*i+1;
    int m = s + (e-s)/2;
    build(s, m, left, a);
    build(m+1, e, right, a);
    segTree[i] = segTree[left] + segTree[right];
}

void update(vector<ll> &a,int s,int e,int i,int pos,int val){
    if(s==e){
      a[pos] = val;
      segTree[i] = a[pos];
      return ;
    }
    int m = s + (e-s)/2;
    if(pos<=m)update(a,s,m,2*i,pos,val);
    else update(a,m+1,e,2*i+1,pos,val);
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
    build(0, n-1, 1, a);
    while(q--) {
        ll op, l, r;
        cin >> op >> l >> r;
        if(op == 1)update(a,0,n-1,1,l-1,r);
        else cout << query(0, n-1, l-1, r-1,1) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    solve();
    return 0;
}
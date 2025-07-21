// #include<bits/stdc++.h>
// #include<iostream>
// using namespace std;
// #define ll long long int

// const int N = 2e5+5;
// int n, q;
// vector<ll> seg(4*N);
// vector<ll> lazy(4*N);

// void build(int s, int e, int i, vector<ll> &a) {
//     if (s == e) {
//         seg[i] = a[s];
//         return;
//     }
//     int m = (s + e) / 2;
//     build(s, m, 2*i, a);
//     build(m+1, e, 2*i+1, a);
//     seg[i] = seg[2*i]+seg[2*i+1];
// }

// void push1(int s, int e, int i) {
//     if (lazy[i] != 0) {
//         seg[i] += lazy[i];
//         if (s != e) {
//             lazy[2*i] += lazy[i];
//             lazy[2*i+1] += lazy[i];
//         }
//         lazy[i] = 0;
//     }
// }

// void push2(int s, int e, int i) {
//     if (lazy[i] != 0) {
//         seg[i] = lazy[i];
//         if (s != e) {
//             lazy[2*i] = lazy[i];
//             lazy[2*i+1] = lazy[i];
//         }
//         lazy[i] = 0;
//     }
// }

// void update1(int s, int e, int i, int l, int r, ll val) {
//     push1(s, e, i);
//     if (r < s || e < l) return;
//     if (l <= s && e <= r) {
//         lazy[i] += val;
//         push1(s, e, i);
//         return;
//     }
//     int m = (s + e) / 2;
//     update1(s, m, 2*i, l, r, val);
//     update1(m+1, e, 2*i+1, l, r, val);
// }

// void update2(int s, int e, int i, int l, int r, ll val) {
//     push2(s, e, i);
//     if (r < s || e < l) return;
//     if (l <= s && e <= r) {
//         lazy[i] = val;
//         push2(s, e, i);
//         return;
//     }
//     int m = (s + e) / 2;
//     update2(s, m, 2*i, l, r, val);
//     update2(m+1, e, 2*i+1, l, r, val);
// }

// ll query(int s, int e, int i, int idx) {
//     // push(s, e, i);
//     if (s == e) return seg[i];
//     int m = (s + e) / 2;
//     if (idx <= m) return query(s, m, 2*i, idx);
//     else return query(m+1, e, 2*i+1, idx);
// }

// int main() {
//     cin >> n >> q;
//     vector<ll> a(n);
//     for (int i = 0; i < n; i++) cin >> a[i];

//     build(0, n-1, 1, a);

//     while (q--) {
//         int op;
//         cin >> op;
//         if (op == 1) {
//             int a,b;
//             ll x;
//             cin>>a>>b;
//             cin>>x;
//             a--,b--;
//             update

//         } else if(op == 2) {
//             int a,b;
//             ll x;
//             cin>>a>>b;
//             cin>>x;
//             a--,b--;

//         } else {
//             int a,b;cin>>a>>b;
//             a--,b--;
//         }
//     }
// }

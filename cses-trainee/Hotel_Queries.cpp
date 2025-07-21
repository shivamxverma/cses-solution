#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long int

// Build
const int N = 2e5+5;
int n,q;
vector<ll> seg(4*N+10);
void build(int s,int e,int i,vector<ll> &a){
    if(s == e){
        seg[i] = a[s];
        return;
    }
    int m = (s+e)/2;
    build(s,m,2*i,a);
    build(m+1,e,2*i+1,a);
    seg[i] = max(seg[2*i],seg[2*i+1]);
}

// Update 
void update(int s, int e, int i,ll val) {
    if (s == e) {
        seg[i] -= val;
        cout << s << " ";
        return;
    } 
    int mid = (s + e) / 2;
    if (seg[i * 2] >= val) update(s,mid,2*i,val);
    else update(mid+1,e,2*i+1,val);

    seg[i] = max(seg[i * 2], seg[i * 2 + 1]);
}

// Query 
// ll Query(int s, int e, int i, int l, int r) {
//     if (r < s || l > e) return LLONG_MAX;       
//     if (l <= s && e <= r) return seg[i];       

//     int m = (s + e) / 2;
//     ll left = Query(s, m, 2 * i, l, r);
//     ll right = Query(m + 1, e, 2 * i + 1, l, r);
//     return min(left, right);                   
// }

int main(){
    cin>>n>>q;
    vector<ll> a(n+1);
    for(int i=1 ; i<=n ; i++)cin>>a[i];

    build(1,n,1,a);

    while (q--) {
		int x;
		cin >> x;
		if (seg[1] < x) cout << "0 ";
		else update(1,n,1,x);
	}
}

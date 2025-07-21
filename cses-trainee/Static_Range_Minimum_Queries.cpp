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
    seg[i] = min(seg[2*i],seg[2*i+1]);
}

// Update 
void update(int s, int e, int i, int pos, ll val) {
    if (s == e) {
        seg[i] = val;
        return;
    }
    int m = (s + e) / 2;
    if (pos <= m)
        update(s, m, 2 * i, pos, val);
    else
        update(m + 1, e, 2 * i + 1, pos, val);

    seg[i] = min(seg[2 * i], seg[2 * i + 1]);
}

// Query 
ll Query(int s, int e, int i, int l, int r) {
    if (r < s || l > e) return LLONG_MAX;       
    if (l <= s && e <= r) return seg[i];       

    int m = (s + e) / 2;
    ll left = Query(s, m, 2 * i, l, r);
    ll right = Query(m + 1, e, 2 * i + 1, l, r);
    return min(left, right);                   
}

int main(){
    cin>>n>>q;
    vector<ll> a(n);
    for(int i=0 ; i<n ; i++)cin>>a[i];

    build(0,n-1,1,a);

    while(q--){
        int x,y;cin>>x>>y;
        x--,y--;
        cout << Query(0,n-1,1,x,y) << endl;
    }
}

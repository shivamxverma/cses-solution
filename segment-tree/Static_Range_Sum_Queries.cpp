#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const int N = 200007;

vector<ll> segTree(4*N+7,-1);

void build(vector<ll> &a,int s,int e,int i){
   if(s==e){
    segTree[i] = a[s];
    return ;
   }
   int mid = s + (e-s)/2;
   build(a,s,mid,2*i);
   build(a,mid+1,e,2*i+1);
   segTree[i] = segTree[2*i] + segTree[2*i+1];
}

ll query(int s,int e,int l,int r,int i){
    if(s>r || e<l) return 0;
    if(l <= s && e <= r) return segTree[i];
    int m = s + (e-s)/2;
    return query(s, m, l, r, 2*i) + query(m+1, e, l, r, 2*i+1);
}

void solve(){
    int n,q;cin>>n>>q;
    vector<ll> a(n);
    for(int i=0 ; i<n ; i++){
      cin>>a[i];
    }
    build(a,0,n-1,1);
    while(q--){
      int l,r;cin>>l>>r;
      l--,r--;
      cout << query(0,n-1,l,r,1) << endl;
    }
}

int main(){
  solve();
  return 0;
}




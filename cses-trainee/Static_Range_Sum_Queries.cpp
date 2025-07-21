#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// Build

int n,m;

vector<int> seg(4*n);

int build(int s,int e,int i,vector<int> &a){
    if(s == e){
        seg[i] = a[s];
        return INT_MAX;
    }

    int m = (s+e)/2;

    int left = build(s,m,2*i,a);
    int right = build(m+1,e,2*i+1,a);

    return min(left,right);
}

// Update 

// Query 

int main(){
    cin>>n>>m;
    vector<long long int> pre = {0};
    for(int i=0 ; i<n ; i++){
        int x;cin>>x;
        pre.push_back(pre.back()+x);
    }

    while(m--){
        int x,y;cin>>x>>y;
        x--,y--;
        cout << pre[y+1]-pre[x] << endl;
    }
}

// Jai shree Ram

#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> &a,pair<int,int> &b){
    // if(a.second == b.second) return a.first < b.first;

    return a.second < b.second;
}

void MahavirCoder(){
    int n;cin>>n;
    vector<pair<int,int>> entry;

    for(int i=0 ; i<n ; i++){
        int x,y;cin>>x>>y;
        entry.push_back({x,y});
    }

    sort(entry.begin(),entry.end(),cmp);

    int ans = 0,cur = 1,prev = entry[0].second;

    for(int i=1 ; i<n ; i++){
        if(entry[i].first >= prev){
            cur++;
            prev = entry[i].second;
        } 
    } 
    cout << cur << endl;
}

int main(){
    int t = 1;
    // cin>>t;
    while(t--){
        MahavirCoder();
    }
}